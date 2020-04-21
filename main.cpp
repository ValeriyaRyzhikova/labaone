#include <QApplication>
#include <QList>
#include <QString>
#include <QObject>
#include <QThread>
#include "fmanager.h"
#include "FWatcher.h"
#include "QTimer"
#include <QSharedPointer>
#include <QPointer>
#include "mainwindow.h"





int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //E:/qt/file/kum.txt
    return a.exec();
}
