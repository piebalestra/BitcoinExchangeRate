#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QString url ="https://www.bitstamp.net/api/v2/ticker/btceur/";
    int update = 10000; //ms
    QString title = "Bitcoin Exchange Rate";

    MainWindow w(title, url, update);
    w.show();

    return a.exec();
}
