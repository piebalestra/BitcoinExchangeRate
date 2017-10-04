#ifndef EXCHANGERATEWINDOW_H
#define EXCHANGERATEWINDOW_H

#include <QMainWindow>

namespace Ui {
class ExchangeRateWindow;
}

class ExchangeRateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExchangeRateWindow(QWidget *parent = 0);
    ~ExchangeRateWindow();

private:
    Ui::ExchangeRateWindow *ui;
};

#endif // EXCHANGERATEWINDOW_H
