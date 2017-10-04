#ifndef MYNETWORK_H
#define MYNETWORK_H

#include <QObject>

class MyNetwork : public QObject
{
    Q_OBJECT
public:
    explicit MyNetwork(QObject *parent = 0);

signals:

public slots:
};

#endif // MYNETWORK_H