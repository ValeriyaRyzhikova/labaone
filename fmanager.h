#ifndef FMANAGER_H
#define FMANAGER_H
#include <QList>
#include <QFileInfo>
#include <QString>
#include <QTimer>
#include <QTime>
#include<iostream>
using namespace std;

class FManager:public QObject
{
    Q_OBJECT
    static FManager *instance;
    QList<QFileInfo> fileList;
    QList<int> state;
    QTimer timer;
    FManager();
    ~FManager(){delete instance;}
public:
    static FManager *getInstance(){
        if (!instance)
            instance=new FManager;
        return instance;
    }
    void addList(QList<QString>);
    void addFile(QString);
    void delFile(QString);
    void delFile(int);
    int findFile(QString);
    void updateI(int);
    void updateAll();
    QStringList getNameList();
    int returnFileSize(int);
public slots:
    void updateTime();
signals:
    void alterWatcher(QString name, int state, bool existence);
};

#endif // FMANAGER_H
