#include "exchangeratewindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ExchangeRateWindow w;
    w.show();

    return a.exec();
}
