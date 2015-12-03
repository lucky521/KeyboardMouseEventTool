#include "mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isRun = false;
    logstart();
}

MainWindow::~MainWindow()
{
    logstop();
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    isRun = !isRun;
    if(isRun)
    {
        ui->pushButton->setText("Stop");

        wthread = new worker(this);
        wthread->start(QThread::NormalPriority);
        ui->plainTextEdit->appendPlainText("Start to listen...");
    }
    else
    {
        BOOL result = PostThreadMessage(wthread->tid,\
                          WM_NULL,(WPARAM)0,(LPARAM)0);
        if(!result)
            ui->plainTextEdit->appendPlainText("PostThreadMessage error: "+ QString::number(GetLastError()));
        ui->pushButton->setText("ReStart");
        ui->plainTextEdit->appendPlainText("Stop to listen.");
    }
}
