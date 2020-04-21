#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, this, &MainWindow::updateWatcherListWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateManagerListWidget()
{
    ui->managerListWidget->clear();
    ui->managerListWidget->addItems(FManager::getInstance()->getNameList());
}

void MainWindow::updateWatcherListWidget()
{
    int i = ui->watcherListWidget->currentRow();
    ui->watcherListWidget->clear();
    for(int i=0; i<listWatcher.size(); i++)
        ui->watcherListWidget->addItem(listWatcher[i].printWatcher());
    ui->watcherListWidget->setCurrentRow(i);
}

void MainWindow::addFileToManager()
{
    FManager::getInstance()->addFile(ui->managerLineEdit->text());
    updateManagerListWidget();
}

void MainWindow::delFileFromManager()
{
    int i=ui->managerListWidget->currentRow();
    FManager::getInstance()->delFile(i);
    updateManagerListWidget();
}

void MainWindow::addFileToListWatcher()
{
    listWatcher.append(FWatcher(ui->watcherLineEdit->text()));
    QObject :: connect(FManager::getInstance(), &FManager::alterWatcher, &(listWatcher.last()), &FWatcher::changedState);
    FManager::getInstance()->updateI(FManager::getInstance()->findFile(ui->watcherLineEdit->text()));
    //FManager::getInstance()->updateAll();
    updateWatcherListWidget();
}

void MainWindow::delFileFromListWatcher()
{
    int i=ui->watcherListWidget->currentRow();
    listWatcher.removeAt(i);
    updateWatcherListWidget();
}

void MainWindow::renameWatcher()
{
    int i=ui->watcherListWidget->currentRow();
    listWatcher[i].change(ui->watcherLineEdit->text());
    FManager::getInstance()->updateI(FManager::getInstance()->findFile(ui->watcherLineEdit->text()));
    updateWatcherListWidget();
}



