#include <string>

#include "process_window.h"
#include "ui_process_window.h"
#include "stringutils.h"

process_window::process_window(QWidget *parent) :
    QMainWindow     (parent),
    ui              (new Ui::process_window),
    m_process       ()
{
    ui->setupUi(this);
}

process_window::~process_window()
{
    delete ui;
}

void process_window::set_process(pw::process_ptr proc)
{
    //Store the process
    m_process = proc;

    //Update the window title accordingly
    __update_window_title();
}

void process_window::__update_window_title()
{
    std::string window_title = pw::stringutils::format("%s (%s)", m_process->pid_str().c_str(), m_process->started_as().c_str());
    this->setWindowTitle(QString(window_title.c_str()));
}
