#include "FWatcher.h"

FWatcher::FWatcher(QString name)
{
    nameFile=name;
    QFileInfo file(name);
    existenceFile=file.exists();
    state=file.size();
}

QString FWatcher::printWatcher()
{
    QString stringForPrint("\nname: ");
    stringForPrint += nameFile + QString(" size:") + QString::number(state) + QString(" sushestvov: ") + QString::number(existenceFile);
    return stringForPrint;
}

void FWatcher::changedState(QString name)
{
    if (name==nameFile)
    {
        QFileInfo file(name);
        state=file.size();
    }
}

void FWatcher::change(const char *new_text)
{
  nameFile=new_text;
  delete new_text;
}

FWatcher::FWatcher()
{
    nameFile="";
    state=-1;
    existenceFile=false;
}

FWatcher::FWatcher(const FWatcher &other)
{
    nameFile=other.nameFile;
    state=other.state;
    existenceFile=other.existenceFile;
}

