#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QObject>
#include <QThread>
#include "fmanager.h"
#include "FWatcher.h"
#include "QTimer"
#include <QSharedPointer>
#include <QPointer>


QList<QPointer<FWatcher>> listWatcher;

void connectOneWatcher(FWatcher* w){
    QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, w, &FWatcher::changedState);
}


void connectWatcher(QList<QPointer<FWatcher>> &listWather)
{
    for (QPointer<FWatcher> watcher: listWather)
        QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, watcher.data(), &FWatcher::changedState);
}



void printWatcherlist0(QList<QPointer<FWatcher>> &listWather)
{
    cout<<"\n";
    for(QPointer<FWatcher> watcher:listWather)
        cout<<watcher->printWatcher().toStdString();
}

void printWatcherlist()
{
    cout<<"\n";
    for(QPointer<FWatcher> watcher: listWatcher)
        cout<<watcher->printWatcher().toStdString();
}


void printOneWatcher(FWatcher* w)
{
    cout<< w->printWatcher().toStdString() << endl;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FManager *F = FManager::getInstance();
    listWatcher.append(QPointer<FWatcher>(new FWatcher("E:/qt/file/tum.txt")));
    listWatcher.append(QPointer<FWatcher>(new FWatcher("E:/qt/file/kum.txt")));
    listWatcher.append(QPointer<FWatcher>(new FWatcher("E:/qt/file/rum.txt")));

    QList<QString> nameList;
    nameList<<"E:/qt/file/rum.txt"<<"E:/qt/file/kum.txt";
    F->addList(nameList);

    F->addFile("E:/qt/file/tum.txt");

    connectWatcher(listWatcher);

    printWatcherlist();

    QTimer timer;
    timer.setInterval(5000);
    QObject::connect(&timer, &QTimer::timeout, printWatcherlist);
    timer.start();

    listWatcher.removeAt(0);
    listWatcher[0]->change("lotv");
    QFile *file=new QFile("E:/qt/file/rum.txt");
    if (file->open(QIODevice::Append)) {
        file->write("punpun");
        file->close();
    }

    return a.exec();
}
