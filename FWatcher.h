#ifndef FNABLUDATEL_H
#define FNABLUDATEL_H
#include <QList>
#include <QFile>
#include <QString>
#include <QObject>
#include<iostream>
#include<QStringList>
using namespace std;


class FWatcher: public QObject
{
    Q_OBJECT
    int state;
    bool existenceFile;
    QString nameFile;
public:
    FWatcher(QString);
    QString getToStringInfo();
    void renameFile(QString);
    FWatcher();
    FWatcher(const FWatcher &other);
    FWatcher &operator=(const FWatcher &other);
    ~FWatcher(){}
    QString getNameFile();
public slots:
    void changedState(QString name, int state, bool existence);
signals:
    void signalUpdateWiget();
};

#endif // FWATCHER_H
