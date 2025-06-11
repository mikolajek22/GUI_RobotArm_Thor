#ifndef MODBUSTCP_H
#define MODBUSTCP_H

#include <QObject>
#include <QTcpSocket>
#include <QString>

#define CONNECTION_TIMEOUT      5000

class modbusTcp : public QObject
{
    Q_OBJECT
public:
    explicit modbusTcp(QObject *parent, QString addr, quint16 port);

signals:

public slots:
    bool connectToServer();
    void disconnectFromServer();
    void sendData();

private slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onError();
private:
    QTcpSocket *socket;
    QString svrIpAddr;
    quint16 port;
};

#endif // MODBUSTCP_H
