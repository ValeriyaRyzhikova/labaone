#include "FWatcher.h"

FWatcher::FWatcher(QString name)
{
    nameFile=name;
    state=-1;
    existenceFile=0;
}

QString FWatcher::getToStringInfo()
{
    QString stringForPrint("name: ");
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
        emit signalUpdateWiget();
    }
}

void FWatcher::renameFile(QString newText)
{
    nameFile = newText;
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

QString FWatcher::getNameFile()
{
    return nameFile;
}
