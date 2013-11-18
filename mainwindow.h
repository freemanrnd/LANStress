/*
 * File:   mainwindow.h
 * Author: Oleg Kurbatov
 *
 * Created on 25 Октябрь 2010 г., 4:02
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "QCloseEvent"
#include "flooder.h"
#include "flood_ruller.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
void closeEvent(QCloseEvent *event);
private:
    Ui::MainWindow *ui_;
    Flooder *fthread_;
    FloodRuller *frthread_;
    int getIPAddr();
    void startFlood();
    void stopFlood();
private slots:
    void RB_TCP_clicked();
    void RB_UDP_clicked();
    void E_IPAddr_textChanged();
    void PB_ON_clicked();
    void PB_OFF_clicked();
};

#endif // MAINWINDOW_H
