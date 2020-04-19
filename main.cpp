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


QList<FWatcher> listWatcher;

void connectOneWatcher(FWatcher w){
    QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, &w, &FWatcher::changedState);
}


void connectWatcher()
{
    for (int i=0; i<listWatcher.size(); i++)
        QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, &(listWatcher[i]), &FWatcher::changedState);
    FManager::getInstance()->updateAll();

}


void printWatcherlist()
{
    cout<<"\n";
    for (int i=0; i<listWatcher.size(); i++)
        //cout<<1<<endl;
        cout<<(listWatcher[i]).printWatcher().toStdString();
}


void printOneWatcher(FWatcher w)
{
    cout<< w.printWatcher().toStdString() << endl;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    FManager *F = FManager::getInstance();
    listWatcher.append(FWatcher("E:/qt/file/tum.txt"));
    listWatcher.append(FWatcher("E:/qt/file/kum.txt"));
    listWatcher.append(FWatcher("E:/qt/file/rum.txt"));

    QList<QString> nameList;
    nameList<<"E:/qt/file/rum.txt"<<"E:/qt/file/kum.txt";
    F->addList(nameList);

    F->addFile("E:/qt/file/tum.txt");

    connectWatcher();

    printWatcherlist();

    QTimer timer;
    timer.setInterval(5000);
    QObject::connect(&timer, &QTimer::timeout, printWatcherlist);
    timer.start();
    //listWatcher.removeAt(0);
   // listWatcher[0].change("E:/qt/file/pum.txt");
    /*QFile file("E:/qt/file/rum.txt");
    if (file.open(QIODevice::Append)) {
        file.write("punpun");
        file.close();
    }


    F->addFile("E:/qt/file/tum.txt");
    for(int i=0; i<5000000; i++)
    {
        listWatcher.append(FWatcher("E:/qt/file/tum.txt"));
        connectWatcher();
        listWatcher.removeAt(0);
    }
*/
    return a.exec();
}
