/*
 * File:   main.cpp
 * Author: Oleg Kurbatov
 *
 * Created on 24 Октябрь 2010 г., 18:50
 */
#include <QtGui/QApplication>
#include <QTextCodec>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    MainWindow w;
    w.show();
    return a.exec();
}