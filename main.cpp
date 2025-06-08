#include "mainwindow.h"

#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

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
