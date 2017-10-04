#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QLineEdit>
#include <QDateTime>
#include <QString>

#include "network.h"

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
     // Request method GET
     void makeRequest();
     // Retrieve result from GET.
     void retrieveRequest(QByteArray data);
     // Refresh the value in the euro box when it's changed in the bitcoin box.
     void updateValues();

private:
     // Update the value of the two keys
     void parseJson(QString data, QString key1, QString key2);

private:
    Ui::MainWindow *ui;
    Network net;
    QTimer *timer;
    QString url;
    int update;
    double exchangeRate;
    QDateTime timestamp;
};

#endif // MAINWINDOW_H
