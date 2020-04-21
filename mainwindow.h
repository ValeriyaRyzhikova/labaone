#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fmanager.h"
#include "FWatcher.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    void updateManagerListWidget();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<FWatcher> listWatcher;
public slots:
    void addFileToManager();
    void delFileFromManager();
    void addFileToListWatcher();
    void delFileFromListWatcher();
    void renameWatcher();
    void updateWatcherListWidget();

};

#endif // MAINWINDOW_H
