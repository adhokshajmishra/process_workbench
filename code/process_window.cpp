#include "process_window.h"
#include "ui_process_window.h"

process_window::process_window(QWidget *parent) :
    QMainWindow     (parent),
    ui              (new Ui::process_window)
{
    ui->setupUi(this);
}

process_window::~process_window()
{
    delete ui;
}
