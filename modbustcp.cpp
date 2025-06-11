#include "modbustcp.h"
#include <QDebug>

modbusTcp::modbusTcp(QObject *parent, QString addr, quint16 port)
    : QObject{parent}
{
    this->svrIpAddr = addr;
    this->port = port;
    this->socket = new QTcpSocket(this);
    /* HINT: connect signal "connected" to onConnected slot. In this case if "connected" will be sent, then onConnected will be called */
    connect(this->socket, &QTcpSocket::connected, this, &modbusTcp::onConnected);
    connect(this->socket, &QTcpSocket::disconnected, this, &modbusTcp::onDisconnected);
    connect(this->socket, &QTcpSocket::readyRead, this, &modbusTcp::onReadyRead);
}

/* ***** PUBLIC SLOTS (HINT: can be voided externally) ***** */


bool modbusTcp::connectToServer() {

    socket->connectToHost(this->svrIpAddr, this->port);

    if (socket->waitForConnected(CONNECTION_TIMEOUT)) {
        socket->disconnectFromHost();
        qDebug() << "PASSED ";
        return true;
    }
    else {
        qDebug() << "FAILED ";
        return false;
    }
}

void modbusTcp::disconnectFromServer() {
    qDebug() << "Disconnecting from server ";
}
void modbusTcp::sendData() {
    qDebug() << "Data has been sent ";
}

/* ***** PRIVATE SLOTS (HINT: voided internally only) ***** */

void modbusTcp::onConnected() {
    qDebug() << "Connected succesfully ";

}
void modbusTcp::onDisconnected() {
    qDebug() << "Disconnected succesfully ";

}
void modbusTcp::onReadyRead() {
     qDebug() << "Data ready to read";

}
//  not implemented!
void modbusTcp::onError() {
     qDebug() << "Error ocurred";
}

