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
    QString printWatcher();
    void change(QString);
    FWatcher();
    FWatcher(const FWatcher &other);
    FWatcher &operator=(const FWatcher &other);
    ~FWatcher(){}
    QString getNameFile();
public slots:
    void changedState(QString name, int state, bool existence);
};

#endif // FWATCHER_H
