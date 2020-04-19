#include "fmanager.h"

FManager::FManager()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer.start(1000);
}

void FManager::addFile(QString name)
{
    fileList.append(QFile(name));
    state.append(QFile(name).size());
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

void FManager::updateTime()
{

    for(int i=0; i<fileList.size(); i++)
       if ((fileList[i].size())!=state[i])
       {
           QString name = fileList[i].fileName();
           state[i] = fileList[i].size();
           emit alterWatcher(name);
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
