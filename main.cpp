#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QObject>
#include <QThread>
#include "fmanager.h"
#include "FWathcer.h"
#include <QSharedPointer>

void connectWatcher(QList<QSharedPointer<FWatcher>>& listWather)
{
    for (QSharedPointer<FWatcher> watcher: listWather)
        QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, watcher.data(), &FWatcher::changedState);
}


void printWatcherlist(QList<QSharedPointer<FWatcher>>& listWather)
{
    cout<<"\n";
    for(QSharedPointer<FWatcher> watcher:listWather)
        cout<<watcher->printWatcher().toStdString();
}

static void doDeleteLater(QObject *obj)
{
    obj->deleteLater();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FManager *F = FManager::getInstance();
    QList<QSharedPointer<FWatcher>> listWather;
    listWather.append(QSharedPointer<FWatcher>(new FWatcher("E:/qt/file/tum.txt"), doDeleteLater));
    listWather.append(QSharedPointer<FWatcher>(new FWatcher("E:/qt/file/kum.txt"), doDeleteLater));
    listWather.append(QSharedPointer<FWatcher>(new FWatcher("E:/qt/file/rum.txt"), doDeleteLater));

    QList<QString> nameList;
    nameList<<"E:/qt/file/rum.txt"<<"E:/qt/file/kum.txt";
    F->addList(nameList);

    F->addFile("E:/qt/file/tum.txt");

    connectWatcher(listWather);

    printWatcherlist(listWather);
    QThread:: sleep(2);
    cout<<"\n";
    listWather.removeAt(0);
    listWather[1]->change(" tut bil vasfay");
    listWather[0]->change(" 02ujwdq");
    printWatcherlist(listWather);


    return a.exec();
}
