#include "network.h"

Network::Network(QObject *parent) : QObject(parent)
{
    connect(networkAccessManager, SIGNAL(finished(QNetworkReply*)), this, SLOT(retrieveRequest(QNetworkReply*)) );
}

void Network::makeRequest(QString url)
{
    networkAccessManager->get(QNetworkRequest(QUrl(url)));
}

void Network::retrieveRequest(QNetworkReply *reply)
{
    emit(retrieveRequestBind(reply->readAll()));
}
