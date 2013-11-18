/* 
 * File:   flood_ruller.cpp
 * Author: Oleg Kurbatov
 * 
 * Created on 28 Oct 2010, 8:52
 */

#include "flood_ruller.h"
#include "mainwindow.h"

FloodRuller::FloodRuller(Flooder *fth, int fTime, int sTime, QObject* parent) {
    this->fthread_ = fth;
    this->flood_time_ = fTime;
    this->silent_time_ = sTime;
    this->runned_ = 0;
    setParent(parent);
}

FloodRuller::~FloodRuller() {
    stop();
    this->wait();
}

void FloodRuller::run(){
    runned_=1;
    while(runned_){
        fthread_->start(QThread::TimeCriticalPriority);
        msleep(flood_time_);
        fthread_->stop();
        fthread_->wait();
        msleep(silent_time_);
    }
}

void FloodRuller::stop(){
    runned_=0;
}