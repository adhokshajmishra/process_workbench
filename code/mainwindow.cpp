#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "process_window.h"

#include "process.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow         (parent),
    ui                  (new Ui::MainWindow),
    m_process_model     (0, 2), // no rows, two columns
    m_processes         ()
{
    ui->setupUi(this);

    //Do initial refresh
    __refresh_process_list();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::__setup_process_list()
{
    //Clear everything
    m_process_model.clear();

    //Setup headers for the processes table
    m_process_model.setHorizontalHeaderItem(0, new QStandardItem(QString("PID")));
    m_process_model.setHorizontalHeaderItem(1, new QStandardItem(QString("Started as")));

    //Set the selection mode to an entire row, only one row
    //can be selected at the same time and rows are not editiable
    ui->tableProcesses->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableProcesses->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableProcesses->setSelectionMode(QAbstractItemView::SingleSelection);

    //The last column should resize to maximum
    ui->tableProcesses->horizontalHeader()->setStretchLastSection(true);

    //Set the model into the table
    ui->tableProcesses->setModel(&m_process_model);
}

void MainWindow::__refresh_process_list()
{
    //Prepare and clear table view
    __setup_process_list();

    //Get all processes..
    m_processes = pw::process_collection::get_all();

    for(size_t i = 0; i < m_processes.count(); ++i)
    {
        //Get the current process
        pw::process_ptr current_proc = m_processes.get_at(i);

        //Build up a row with two columns
        QList<QStandardItem*> column_fields;
        column_fields.append(new QStandardItem(QString(current_proc->pid_str().c_str())));
        column_fields.append(new QStandardItem(QString(current_proc->started_as().c_str())));

        //Append the row
        m_process_model.appendRow(column_fields);
    }
}

void MainWindow::on_action_Refresh_triggered()
{
    __refresh_process_list();
}

void MainWindow::on_tableProcesses_doubleClicked(const QModelIndex &index)
{
    //Grab the shared pointer to the process that was clicked
    pw::process_ptr clicked_proc = m_processes.get_at(index.row());
    if(!clicked_proc)
        return;

    //Create a new instance of the detail window for a process and pass
    //along the clicked process pointer instance
    process_window *new_window = new process_window;
    new_window->set_process(clicked_proc);

    //Show the new window
    new_window->show();
}
