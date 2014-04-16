/*
 * Process Analyzer is a small tool to analyze processes on standard LINUX
 * platform.
 *
 * Copyright (c) Adhokshaj Mishra, Swen Kooij
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "process.h"
#include "process_collection.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow         (parent),
    ui                  (new Ui::MainWindow),
    m_process_model     (0, 2) // no rows, two columns
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

    //Set the model into the table
    ui->tableProcesses->setModel(&m_process_model);
}

void MainWindow::__refresh_process_list()
{
    //Prepare and clear table view
    __setup_process_list();

    //Get all processes..
    pw::process_collection procs = pw::process_collection::get_all();

    for(size_t i = 0; i < procs.count(); ++i)
    {
        //Get the current process
        pw::process_ptr current_proc = procs.get_at(i);

        //Build up a row with two columns
        QList<QStandardItem*> column_fields;
        column_fields.append(new QStandardItem(QString(current_proc->pid_str())));
        column_fields.append(new QStandardItem(QString(current_proc->started_as())));

        //Append the row
        m_process_model.appendRow(column_fields);
    }
}

void MainWindow::on_action_Refresh_triggered()
{
    __refresh_process_list();
}
