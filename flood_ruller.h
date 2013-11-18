/* 
 * File:   flood_ruller.h
 * Author: Oleg Kurbatov
 *
 * Created on 28 Oct 2010, 8:52
 */

#ifndef _FLOOD_RULLER_H
#define	_FLOOD_RULLER_H

#include "QThread"
#include "flooder.h"

class FloodRuller : public QThread{
Q_OBJECT
public:
    FloodRuller(Flooder* fth,int floodTime,int silentTime,QObject* parent=0);
    virtual ~FloodRuller();
    void stop();
private:
    Flooder* fthread_;
    int flood_time_, silent_time_;
    bool runned_;
    void run();
};

#endif	/* _FLOOD_RULLER_H */

