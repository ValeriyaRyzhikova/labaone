#include "fmanager.h"

FManager::FManager()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer.start(1000);
}

void FManager::addFile(QString name)
{
    fileList.append(QFileInfo(name));
    if (QFileInfo(name).exists())
        state.append(QFileInfo(name).size());
    else
        state.append(-1);
}

void FManager::delFile(QString name)
{
    int index_del=this->findFile(name);
    if (index_del==-1) return;
    fileList.removeAt(index_del);
    state.removeAt(index_del);
}

int FManager::findFile(QString name)
{
    for(int i=0; i<fileList.size(); i++)
        if(fileList[i].fileName()==name)
            return i;
    return -1;
}

void FManager::updateI(int i)
{
    QString name = fileList[i].absoluteFilePath();
    if (fileList[i].exists())
        state[i] = fileList[i].size();
    else
        state[i]=-1;
    emit alterWatcher(name, state[i], fileList[i].exists());
}

void FManager::updateAll()
{
    for(int i=0; i<fileList.size();i++)
        updateI(i);
}

void FManager::updateTime()
{

    for(int i=0; i<fileList.size(); i++){
        fileList[i].refresh();
        if ((fileList[i].size())!=state[i])
            updateI(i);
    }
}

FManager *FManager::instance = 0;

void FManager::addList(QList<QString> name_list)
{
    for(QString name: name_list)
    {
        this->addFile(name);
    }
}
