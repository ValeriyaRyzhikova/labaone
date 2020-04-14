#ifndef FMANAGER_H
#define FMANAGER_H
#include <QList>
#include <QFile>
#include <QString>
#include <QTimer>
#include <QTime>
#include<iostream>
using namespace std;

class FManager:public QObject
{
    Q_OBJECT
    static FManager *instance;
    QList<QFile*> fileList;
    QList<int> state;
    QTimer *timer;
    FManager();
public:
    static FManager *getInstance(){
        if (!instance)
            instance=new FManager;
        return instance;
    }
    void addList(QList<QString>);
    void addFile(QString);
    void delFile(QString);
    int findFile(QString);

public slots:
    void updateTime();
signals:
    void alterWatcher(QString name);
};

#endif // FMANAGER_H
