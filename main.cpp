#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QObject>
#include <QThread>
#include "fmanager.h"
#include "FWathcer.h"
#include "QTimer"
#include <QSharedPointer>


QList<QSharedPointer<FWatcher>>* returnLisWatcher(QList<QSharedPointer<FWatcher>>* list = NULL)//, bool del = 0)
{
    static QList<QSharedPointer<FWatcher>>* l;
    //if (del) l = NULL;
    if (list == NULL) return l;
    else return l=list;
}

void connectOneWatcher(FWatcher* w){
    QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, w, &FWatcher::changedState);
}


void connectWatcher(QList<QSharedPointer<FWatcher>> &listWather)
{
    for (QSharedPointer<FWatcher> watcher: listWather)
        QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, watcher.data(), &FWatcher::changedState);
}


void printWatcherlist0(QList<QSharedPointer<FWatcher>> &listWather)
{
    cout<<"\n";
    for(QSharedPointer<FWatcher> watcher:listWather)
        cout<<watcher->printWatcher().toStdString();
}

void printWatcherlist()
{
    QList<QSharedPointer<FWatcher>> *listWather=returnLisWatcher();
    cout<<"\n";
    for(QSharedPointer<FWatcher> watcher:*listWather)
        cout<<watcher->printWatcher().toStdString();
}


void printOneWatcher(FWatcher* w)
{
    cout<< w->printWatcher().toStdString() << endl;
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

    returnLisWatcher(&listWather);
    QTimer timer;
    timer.setInterval(2000);
    QObject::connect(&timer, &QTimer::timeout, printWatcherlist);
    timer.start();

    listWather[0]->deleteLater();
    listWather.removeAt(0);
    listWather[0]->change("lotv");
    QFile *file=new QFile("E:/qt/file/rum.txt");
    if (file->open(QIODevice::Append)) {
        file->write("punpun");
        file->close();
}


    return a.exec();
}
