#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDirIterator>
#include <QStringList>
#include <QDir>

#include <cctype>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Refresh_triggered()
{
    QStringList list_proc;
    QDir currentDir("/proc");
    currentDir.setFilter(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);
    list_proc = currentDir.entryList();

    for (int i = 0; i < list_proc.count(); ++i)
    {
        if (list_proc[i][0].isDigit())
        {
            ui->lstProcess->addItem(list_proc[i]);
        }
    }
}
