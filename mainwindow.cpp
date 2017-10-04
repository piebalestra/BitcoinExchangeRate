#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QString title, QString url, int update,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    url(url),
    update(update),
    exchangeRate(0.0)
{
    // Set ui context.
    ui->setupUi(this);

    // Set window title.
    this->setWindowTitle(title);

    // lineEditEuro read only.
    ui->lineEditEuro->setReadOnly(true);

    // Invoke makeRequest every update ms.
    timer = new QTimer(this);
    makeRequest();
    connect(timer, SIGNAL(timeout()), this, SLOT(makeRequest()));
    timer->start(update);

    // Retrieve response from url.
    connect(&net, SIGNAL(retrieveRequestBind(QByteArray)), this, SLOT(retrieveRequest(QByteArray)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::makeRequest()
{
    net.makeRequest(url);
}

void MainWindow::retrieveRequest(QByteArray data)
{
    parseJson(data, "last", "timestamp");
}

void MainWindow::parseJson(QString data, QString field1, QString field2)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    timestamp.setTime_t(jsonObject[field2].toString().toLong());
    ui->lineEditEuro->setText(jsonObject[field1].toString());
    ui->labelTimestamp->setText(timestamp.toString("dd-MM-yyyy hh:mm:ss"));
}
