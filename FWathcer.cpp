#include "FWathcer.h"

FWatcher::FWatcher(QString name)
{
    nameFile=name;
    QFile file(name);
    existenceFile=file.exists();
    state=file.size();
    file.close();

}

QString FWatcher::printWatcher()
{
    QString stroka_dla_vyvoda("\nname: ");
    stroka_dla_vyvoda += nameFile + QString(" size:") + QString::number(state) + QString(" sushestvov: ") + QString::number(existenceFile);
    return stroka_dla_vyvoda;


}

void FWatcher::changedState(QString name)
{
    if (name==nameFile)
    {
        QFile file(name);
        state=file.size();
    }
}

void FWatcher::change(const char* new_text)
{
     QFile *file=new QFile(nameFile);
     if (file->open(QIODevice::Append))
             file->write(new_text);
     state=file->size();
     file->close();
     existenceFile=true;
}

FWatcher::FWatcher()
{
    nameFile="";
    state=-1;
    existenceFile=false;
}

FWatcher::FWatcher(const FWatcher& other)
{
    nameFile=other.nameFile;
    state=other.state;
    existenceFile=other.existenceFile;
}

FWatcher& FWatcher::operator=(const FWatcher &other)
{
    nameFile=other.nameFile;
    state=other.state;
    existenceFile=other.existenceFile;
    return *this;
}

