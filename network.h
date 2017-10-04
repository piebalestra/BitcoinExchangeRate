#ifndef NETWORK_H
#define NETWORK_H

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QNetworkReply>

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0);
    void makeRequest(QString endPointRequest);

signals:
    void retrieveRequestBind(QByteArray);
public slots:
    void retrieveRequest(QNetworkReply *reply);
private:
    QNetworkAccessManager *networkAccessManager = new QNetworkAccessManager(this);
};

#endif // MYNETWORK_H
