#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString title, QString url, int update,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    // Set ui context.
    ui->setupUi(this);

    // Set window title.
    this->setWindowTitle(title);

    // Invoke makeRequest every update ms.
    timer = new QTimer(this);
    makeRequest();
    connect(timer, SIGNAL(timeout()), this, SLOT(makeRequest()));
    timer->start(update);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeRequest()
{
    net.makeRequest(url);
}
