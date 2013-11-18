/* 
 * File:   flooder.h
 * Author: Oleg Kurbatov
 *
 * Created on 25 Oct 2010, 2:22
 */

#ifndef _FLOODER_H
#define	_FLOODER_H

#include "QThread"

/**
 *  
 */
class Flooder : public QThread {
    Q_OBJECT
    enum FloodType {TCP, UDP};
public:
    Flooder(QObject* parent=0);
    Flooder(QObject* parent,char* ipaddr,int port, char flags, int datasize, int freq=0);
    Flooder(QObject* parent, int port, int datasize, int freq=0);
    virtual ~Flooder();
    void stop();
protected:
    void run();
    char* makeTCP(int dport, char flags, int length);
    char* makeUDP(int dport, int length);
    short getChecksum(char* const packet,int length);
private:
    bool flood_;
    FloodType flood_type_;
    char *ipaddr_, flags_;
    int port_, data_size_, freq_;

};

#endif	/* _FLOODER_H */

