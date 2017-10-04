#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>

class MyNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MyNetwork(QObject *parent = 0);
    void makeRequest(QString endPointRequest);

signals:
    void retrieveRequestBind(QByteArray);
public slots:
    void retrieveRequest(QNetworkReply *reply);
private:
    QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
};

#endif // MYNETWORK_H
