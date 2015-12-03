#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "hook.h"
#include "applog.h"
#include "worker.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    bool isRun;

    worker *wthread;

};

#endif // MAINWINDOW_H
