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

    // Retrieve result from GET.
    connect(&net, SIGNAL(retrieveRequestBind(QByteArray)), this, SLOT(retrieveRequest(QByteArray)));

    // Refresh the value in the euro box when it's changed in the bitcoin box.
    connect(ui->lineEditBitcoin, SIGNAL(textChanged(QString)), this, SLOT(updateValues()));

    // Repat request method GET at fixed interval.
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

void MainWindow::retrieveRequest(QByteArray data)
{
    parseJson(data, "last", "timestamp");
    updateValues();

}

void MainWindow::parseJson(QString data, QString key1, QString key2)
{
    QJsonDocument jsonResponse = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject jsonObject = jsonResponse.object();
    exchangeRate = jsonObject[key1].toString().toDouble();
    timestamp.setTime_t(jsonObject[key2].toString().toLong());;
}

void MainWindow::updateValues()
{
    QString bitcoin = ui->lineEditBitcoin->text();
    QString text;
    text.sprintf("%.2f", exchangeRate * bitcoin.toDouble());
    ui->lineEditEuro->setText(text);
    ui->labelTimestamp->setText(timestamp.toString("dd-MM-yyyy hh:mm:ss"));
}
