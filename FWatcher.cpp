#include "FWatcher.h"

FWatcher::FWatcher(QString name)
{
    nameFile=name;
}

QString FWatcher::printWatcher()
{
    QString stringForPrint("\nname: ");
    stringForPrint += nameFile + QString(" size:") + QString::number(state) + QString(" sushestvov: ") + QString::number(existenceFile);
    return stringForPrint;
}

void FWatcher::changedState(QString name, int _state, bool _existence)
{
    if (name==nameFile)
    {
        if (_existence)
            state=_state;
        else
            state=0;
        existenceFile=_existence;
    }
}

void FWatcher::change(const char *new_text)
{
  nameFile=new_text;
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

