#include "mynetwork.h"

MyNetwork::MyNetwork(QObject *parent) : QObject(parent)
{
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(retrieveRequest(QNetworkReply*)) );
}

void MyNetwork::makeRequest(QString endPointRequest)
{
    networkAccessManager->get(QNetworkRequest(QUrl(endPointRequest)));
}

void MyNetwork::retrieveRequest(QNetworkReply *reply)
{
    QByteArray data = reply->readAll();
    emit(retrieveRequestBind(data));
}
