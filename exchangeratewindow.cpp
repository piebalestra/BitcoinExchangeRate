#include "exchangeratewindow.h"
#include "ui_exchangeratewindow.h"

ExchangeRateWindow::ExchangeRateWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExchangeRateWindow)
{
    ui->setupUi(this);
}

ExchangeRateWindow::~ExchangeRateWindow()
{
    delete ui;
}
