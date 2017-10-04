#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLineEdit>
#include <QDateTime>
#include <QString>

#include "mynetwork.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString title, QString url, int update, QWidget *parent = 0);
    ~MainWindow();

private slots:
     void makeRequest();
     void retrieveRequest(QByteArray data);
     void updateValues();

private:
     void parseJson(QString data, QString field1, QString field2);

private:
    Ui::MainWindow *ui;
    MyNetwork net;
    QTimer *timer;
    QString url;
    int update;
    double exchangeRate;
    QDateTime timestamp;
};

#endif // MAINWINDOW_H
