/*
 * File:   mainwindow.cpp
 * Author: Oleg Kurbatov
 *
 * Created on 25 Oct 2010, 4:02
 */
//binary literals macros
#define BIN__N(x) (x) | (x>>3) | (x>>6) | (x>>9)
#define BIN__B(x) ((x) & 0xf) | ((x)>>12 & 0xf0)
#define BIN8(v) (BIN__B(BIN__N(0x##v)))
#define BIN16(x1,x2) \ ((BIN(x1)<<8)+BIN(x2))
#define BIN24(x1,x2,x3) \ ((BIN(x1)<<16)+(BIN(x2)<<8)+BIN(x3))
#define BIN32(x1,x2,x3,x4) \ ((BIN(x1)<<24)+(BIN(x2)<<16)+(BIN(x3)<<8)+BIN(x4))

#include <iostream>
#include <stdio.h>
#include <qmessagebox.h>
#include <math.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);
    connect(ui_->RB_TCP,SIGNAL(clicked()),this,SLOT(RB_TCP_clicked()));
    connect(ui_->RB_UDP,SIGNAL(clicked()),this,SLOT(RB_UDP_clicked()));
    connect(ui_->E_IPAddr,SIGNAL(editingFinished()),this,SLOT(E_IPAddr_textChanged()));
    connect(ui_->PB_ON,SIGNAL(clicked()),this,SLOT(PB_ON_clicked()));
    connect(ui_->PB_OFF,SIGNAL(clicked()),this,SLOT(PB_OFF_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui_;
}

/**
 * Sets availability of controls when TCP protocol is chosen
 */
void MainWindow::RB_TCP_clicked(){
    ui_->E_IPAddr->setEnabled(1);
    ui_->CB_CWR->setEnabled(1);
    ui_->CB_ECN->setEnabled(1);
    ui_->CB_URG->setEnabled(1);
    ui_->CB_ACK->setEnabled(1);
    ui_->CB_PSH->setEnabled(1);
    ui_->CB_RST->setEnabled(1);
    ui_->CB_SYN->setEnabled(1);
    ui_->CB_FIN->setEnabled(1);
    if(getIPAddr()){
        ui_->PB_ON->setEnabled(1);
    }else{
        ui_->PB_ON->setEnabled(0);
    }
}

/**
 * Sets availability of controls when UDP protocol is chosen
 */
void MainWindow::RB_UDP_clicked(){
    ui_->E_IPAddr->setEnabled(0);
    ui_->CB_CWR->setEnabled(0);
    ui_->CB_ECN->setEnabled(0);
    ui_->CB_URG->setEnabled(0);
    ui_->CB_ACK->setEnabled(0);
    ui_->CB_PSH->setEnabled(0);
    ui_->CB_RST->setEnabled(0);
    ui_->CB_SYN->setEnabled(0);
    ui_->CB_FIN->setEnabled(0);
    ui_->PB_ON->setEnabled(1);
}

/**
 * Handles changes in the IP-address field.
 */
void MainWindow::E_IPAddr_textChanged(){
    if(getIPAddr()){
        ui_->PB_ON->setEnabled(1);
    }else{
        ui_->PB_ON->setEnabled(0);
    }
}

/**
 * Converts IP-address from a string to int value.
 * @return int representation of IP-address
 */
int MainWindow::getIPAddr(){
    QString ipstr=ui_->E_IPAddr->text();
    int len=ipstr.length();
    if(len<7)return 0;
    char octets[4][3];
    for(int i=0,j=0,k=0;j<len;j++){
        if(ipstr[j].isNumber()){
            octets[i][k++]=ipstr[j].toAscii();
        }else{
            if(j==0)return 0;
            i++;
            k=0;
        }
    }
    return (atoi(octets[0])<<24)+(atoi(octets[1])<<16)+(atoi(octets[2])<<8)+atoi(octets[3]);    
}

/**
 * Handles a click on the flood turning on button.
 */
void MainWindow::PB_ON_clicked(){
    ui_->E_IPAddr->setEnabled(0);
    ui_->CB_CWR->setEnabled(0);
    ui_->CB_ECN->setEnabled(0);
    ui_->CB_URG->setEnabled(0);
    ui_->CB_ACK->setEnabled(0);
    ui_->CB_PSH->setEnabled(0);
    ui_->CB_RST->setEnabled(0);
    ui_->CB_SYN->setEnabled(0);
    ui_->CB_FIN->setEnabled(0);
    ui_->RB_TCP->setEnabled(0);
    ui_->RB_UDP->setEnabled(0);
    ui_->PB_ON->setEnabled(0);
    ui_->PB_OFF->setEnabled(1);
    startFlood();
}

/**
 * Handles a click on the flood turning off button.
 */
void MainWindow::PB_OFF_clicked(){
    if(ui_->RB_TCP->isChecked()){
        RB_TCP_clicked();
    }else if(ui_->RB_UDP->isChecked()){
        RB_UDP_clicked();
    }
    ui_->RB_TCP->setEnabled(1);
    ui_->RB_UDP->setEnabled(1);
    ui_->PB_ON->setEnabled(1);
    ui_->PB_OFF->setEnabled(0);
    ui_->BAR_Load->setEnabled(0);
    ui_->BAR_Load->setValue(0);
    stopFlood();
}

/**
 * Prepares and starts flooding
 */
void MainWindow::startFlood(){
    int port = ui_->SB_Port->value();
    int packetsize = ui_->SB_PacketSize->value();
    int freq=ui_->SB_FloodFreq->value();
    ui_->BAR_Load->setEnabled(1);
    ui_->BAR_Load->setValue(freq/10000);
    if (ui_->RB_TCP->isChecked()) {
        char flags = 0;//далее устанавливаем флаги пакета
        if (ui_->CB_CWR->isChecked())flags += BIN8(10000000);
        if (ui_->CB_ECN->isChecked())flags += BIN8(01000000);
        if (ui_->CB_URG->isChecked())flags += BIN8(00100000);
        if (ui_->CB_ACK->isChecked())flags += BIN8(00010000);
        if (ui_->CB_PSH->isChecked())flags += BIN8(00001000);
        if (ui_->CB_RST->isChecked())flags += BIN8(00000100);
        if (ui_->CB_SYN->isChecked())flags += BIN8(00000010);
        if (ui_->CB_FIN->isChecked())flags += BIN8(00000001);

        int len = ui_->E_IPAddr->text().length();
        char *addr = new char[len+1];
        for (int i = 0; i < len; i++)addr[i] = ui_->E_IPAddr->text()[i].toAscii();
        addr[len]='\0';

        fthread_ = new Flooder(this, addr, port, flags, packetsize, freq);
    }else if (ui_->RB_UDP->isChecked()) {
        fthread_ = new Flooder(this, port, packetsize, freq);
    }
    if(ui_->SB_SilentTime->value()==0){//если без задержек
        fthread_->start(QThread::TimeCriticalPriority);
    }else{//если с задержками
        frthread_=new FloodRuller(fthread_,ui_->SB_FloodTime->value(),ui_->SB_SilentTime->value(),this);
        frthread_->start(QThread::TimeCriticalPriority);
    }
}

/**
 * Stops flooding
 */
void MainWindow::stopFlood(){
    if(ui_->SB_SilentTime->value()==0){
        fthread_->stop();
        fthread_->wait();
    }else{//если есть задержки между эпизодами флуда сначала останавливаем floodRuller
        frthread_->stop();
        frthread_->wait();
        delete frthread_;
    }
    delete fthread_;
}

/**
 * Handles an event of closing the window
 * @param event
 */
void MainWindow::closeEvent(QCloseEvent *event){
    if(ui_->BAR_Load->isEnabled()) stopFlood();
    event->accept();
};