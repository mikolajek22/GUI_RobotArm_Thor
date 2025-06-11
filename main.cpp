#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QTcpSocket>
#include <QDebug>
#include "QString"
#include "QThread"
#include "modbustcp.h"


int init_tasks();

QThread *modbusTcp_thread;
modbusTcp *modbusTcpClient;

const QString addr = "192.168.1.10";
const quint16 port = 502;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /* ***** INITIALIZE TASKS ****** */
    init_tasks();
    /* ***** READ QSS STYLE FILE ****** */
    QFile styleFile(":/styles/styles.qss");
    if (styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString styleSheet = QLatin1String(styleFile.readAll());
        a.setStyleSheet(styleSheet);
        styleFile.close();
    }

    MainWindow w;
    w.show();
    return a.exec();
}

int init_tasks() {
    modbusTcp_thread    = new QThread;
    modbusTcpClient     = new modbusTcp(nullptr, addr, port);   // object cannot have parent.
    modbusTcpClient->moveToThread(modbusTcp_thread);

    QObject::connect(modbusTcp_thread, &QThread::started, modbusTcpClient, &modbusTcp::connectToServer);
    modbusTcp_thread->start();
    return 0;
}
