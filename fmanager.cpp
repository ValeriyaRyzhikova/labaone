#include "fmanager.h"

FManager::FManager()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer.start(1000);
}

void FManager::addFile(QString name)
{
    if (findFile(name)<0){
        QFileInfo f(name);
        fileList.append(f);
        state.append(returnFileSize(fileList.size()-1));
    }
}

int FManager::returnFileSize(int i)
{
    fileList[i].refresh();
    if (fileList[i].exists())
        return (fileList[i].size());
    else
        return (-1);
}


void FManager::delFile(QString name)
{
    int indexDel=findFile(name);
    if (indexDel < 0) return;
    fileList.removeAt(indexDel);
    state.removeAt(indexDel);
}

void FManager::delFile(int i)
{
    if (i < 0) return;
    fileList.removeAt(i);
    state.removeAt(i);
}

int FManager::findFile(QString name)
{
    QFileInfo f(name);
    return FManager::getNameList().indexOf(f.absoluteFilePath());
}

void FManager::updateI(int i)
{
    if (i >= 0)
    {
        QString name = fileList[i].absoluteFilePath();
        state[i]=returnFileSize(i);
        emit alterWatcher(name, state[i], fileList[i].exists());
    }
}

void FManager::updateAll()
{
    for(int i=0; i<fileList.size();i++)
        updateI(i);
}

void FManager::updateTime()
{

    for(int i=0; i<fileList.size(); i++){
        if (state[i]!=returnFileSize(i))
            updateI(i);
    }
}

FManager *FManager::instance = 0;

QStringList FManager::getNameList()
{
    QStringList nameList;
    for(int i=0; i<fileList.size(); i++)
            nameList.append(fileList[i].absoluteFilePath()/* + QString::number(state[i])*/);
    return nameList;
}





void FManager::addList(QList<QString> name_list)
{
    for(QString name: name_list)
    {
        this->addFile(name);
    }
}
