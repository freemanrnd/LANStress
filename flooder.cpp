/* 
 * File:   flooder.cpp
 * Author: Oleg Kurbatov
 * 
 * Created on 25 Oct 2010, 2:22
 */

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "flooder.h"

Flooder::Flooder(QObject* parent) : flood_(FALSE) {
    setParent(parent);
}

Flooder::Flooder(QObject* parent, char *ipaddr, int port, char flags, int datasize, int frequency) {
    setParent(parent);
    this->ipaddr_ = ipaddr;
    this->port_ = port;
    this->flags_ = flags;
    this->data_size_ = datasize;
    
    this->flood_ = FALSE;
    this->flood_type_ = TCP;
    this->freq_ = frequency;
}

Flooder::Flooder(QObject* parent, int port, int datasize, int frequency) {
    setParent(parent);
    this->port_ = port;
    this->data_size_ = datasize;
    
    this->flood_ = FALSE;
    this->flood_type_ = UDP;
    this->freq_ = frequency;
}

Flooder::~Flooder() {
    stop();
    this->wait();
}

void Flooder::stop() {
    flood_ = FALSE;
}

void Flooder::run() {
    int sockfd, addrlen, datalen, result;
    sockaddr_in address;
    char *ipaddr = this->ipaddr_;
    unsigned long sleepTime;

    //delay between package sending
    //DOTO inject delay provider
    if (this->freq_ == 0) {
        sleepTime = 0;
    } else {
        sleepTime = 1000000 / this->freq_;
    }

    //opening socket
    if (flood_type_ == TCP) {
        datalen = 32;
        sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    } else {
        datalen = 8;
        sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);
    }
    if (sockfd == -1) {
        perror("Ошибка создания сокета");
        //QMessageBox::critical(this, "Critical error", "Socket opening error", QMessageBox::Ok, QMessageBox::Ok);
        //exit(EXIT_FAILURE);
    }

    //формируем целевой адрес
    address.sin_family = AF_INET;
    if (flood_type_ == TCP) {
        address.sin_addr.s_addr = inet_addr(ipaddr);
    } else {
        //TODO add possibility of UDP flooding by IP-address
        address.sin_addr.s_addr = INADDR_BROADCAST;
    }

    address.sin_port = htons(port_);
    addrlen = sizeof (address);

    datalen += data_size_;

    flood_ = TRUE;
    if (flood_type_ == TCP) {
        char *tcp;
        while (flood_) {
            tcp = makeTCP(port_, flags_, datalen);
            result = sendto(sockfd, tcp, datalen, 0, (sockaddr*) & address, addrlen);
            delete [] tcp;
            if (result == -1) {
                perror("Sending package error");
            }
            usleep(sleepTime);
        }
    } else {
        int broadcast = 1;
        if ((setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast)) == -1) {
            perror("setsockopt - SOL_SOCKET SO_BROADCAST fail");
        }
        char* udp;
        while (flood_) {
            udp = makeUDP(port_, datalen);
            result = sendto(sockfd, udp, datalen, 0, (sockaddr*) & address, addrlen);
            delete [] udp;
            if (result == -1) {
                perror("Sending package error (check your permissions and routing table)");
            }
            usleep(sleepTime);
        }
    }

    ::close(sockfd);
}

/**
 * Makes TCP-package of given length and random content.
 * @param dst_port Destination port
 * @param flags Flags of TCP-package header
 * @param length Length of content in bytes (not less than 32 bytes)
 * @return TCP-package or NULL if an error occurs
 */
char* Flooder::makeTCP(int dst_port, char flags, int length) {
    static int sequence_number = 0; //Sequence number - номер последовательности
    if (length < 32)return NULL; //total data length should be greater than length of package header
    char *snp = (char*) &sequence_number;
    char *dportp = (char*) &dst_port;
    int acknowlwgement_number = 0; //Acknowledgement number - номер пакета, ожидаемого получателем (до него всё успешно получено)
    char *tcp = new char[length]; //TCP-package (a header is the first 32 bytes)

    sequence_number++;
    acknowlwgement_number = rand();
    //TCP package
    tcp[0]=0x2f;tcp[1]=0x00;//source port
    tcp[2]=dportp[1];tcp[3]=dportp[0];//destination port
    tcp[4]=snp[3];tcp[5]=snp[2];tcp[6]=snp[1];tcp[7]=snp[0];//sequence number
    tcp[8]=0x00;tcp[9]=0x00;tcp[10]=0x00;tcp[11]=0x00;//номер подтверждения (an) должен быть равен нулю, если ACK не установлен
    tcp[12]=0x80;//смещение начала данных (длинна заголовка - 4 бита) и зарезервировано (12 бит)
    tcp[13]=flags;//flags CWR ECN-echo URG АСК PSH RST SYN FIN
    tcp[14]=0x18;tcp[15]=0x03;//window - количество байт, которое отправитель данного сегмента может принять
    tcp[16]=0x00;tcp[17]=0x00;//checksum
    tcp[18]=0x00;tcp[19]=0x00;//указатель важности
    tcp[20]=0x00;tcp[21]=0x00;tcp[22]=0x00;tcp[23]=0x00;//options
    tcp[24]=0x00;tcp[25]=0x00;tcp[26]=0x00;tcp[27]=0x00;//options
    tcp[28]=0x00;tcp[29]=0x00;tcp[30]=0x00;tcp[31]=0x00;//options
    //tcp[32]=0xcd;tcp[33]=0xdf;//data

    for (int i = 32; i < length; i++) {
        tcp[i] = static_cast<char> (rand());
    }

    //checksum calculation
    int cs = getChecksum(tcp, length);
    char *pcs = (char*) &cs;
    tcp[16] = pcs[1];
    tcp[17] = pcs[0];

    return tcp;
}

/**
 * Makes UDP-package of given length and random content.
 * @param dst_port Destination port
 * @param length Length of content in bytes (not less than 7 bytes)
 * @return UDP-package or NULL if an error occurs
 */
char* Flooder::makeUDP(int dst_port, int length) {
    if (length < 8)return NULL; //total data length should be greater than length of package header
    char *dportp = (char*) &dst_port;
    char *udp = new char[length]; //UDP-package (a header is the first 8 bytes)

    //UDP packet
    udp[0]=0x2f;udp[1]=0x00;//source port
    udp[2]=dportp[1];udp[3]=dportp[0];//destination port
    udp[4]=0x08;udp[5]=0x00;//package length
    udp[6]=0x00;udp[7]=0x00;//checksum

    for (int i = 8; i < length; i++) {
        udp[i] = static_cast<char> (rand());
    }

    //checksum calculation
    int cs = getChecksum(udp, length);
    char *pcs = (char*) &cs;
    udp[6] = pcs[1];
    udp[7] = pcs[0];

    return udp;
}

/**
 * Calculates a checksum.
 * Рассчитывает контрольную сумму пакета методом вычисления поразрядного дополнения
 * до единицы суммы с поразрядным дополнением всех двухбайтных слов в пакете.
 * @param package a package
 * @param length package length
 * @return a checksum consisting in two bytes
 */
//TODO функция не берёт во внимание псевдозаголовок IP и потому контрольная сумма неверна
short Flooder::getChecksum(char* const package, int length) {
    int sum = 0;
    unsigned short *word = (unsigned short*) package;
    if (length % 2 == 1) {//случай нечётного числа байт в пакете
        length--;
        sum += package[length];
        sum = sum << 8;
    }
    for (int i = 0; i < length; i += 2) {
        sum += *word++;
    }
    sum = (sum >> 16)+(sum & 0xffff);
    sum = (sum >> 16)+(sum & 0xffff);
    if (sum != 0xffff) {
        sum = ~sum;
    }
    return sum;
}