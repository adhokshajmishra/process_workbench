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

#include <string>

#include "process_window.h"
#include "ui_process_window.h"
#include "stringutils.h"
#include "call_stack_item.h"
#include "process_status.h"

#include <QString>

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
    __update_callstack();
    __update_process_status();
}

void process_window::__setup_callstack_table()
{
    //Clear everything in there
    m_callstack_model.clear();

    //Setup headers for the processes table
    m_callstack_model.setHorizontalHeaderItem(0, new QStandardItem(QString("Address")));
    m_callstack_model.setHorizontalHeaderItem(1, new QStandardItem(QString("Function")));

    //Set the selection mode to an entire row, only one row
    //can be selected at the same time and rows are not editiable
    ui->tableCallstack->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableCallstack->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableCallstack->setSelectionMode(QAbstractItemView::SingleSelection);

    //The last column should resize to maximum
    ui->tableCallstack->horizontalHeader()->setStretchLastSection(true);

    //Set the model into the table
    ui->tableCallstack->setModel(&m_callstack_model);
}

void process_window::__update_callstack()
{
    //Make sure we have a process
    if(!m_process)
        return;

    //Clear the callstack table
    __setup_callstack_table();

    //Get the callstack for this process
    pw::call_stack callstack = m_process->callstack();
    for(size_t i = 0; i < callstack.size(); ++i)
    {
        //Get the current call within the callstack
        pw::call_stack_item_ptr current_call = callstack[i];

        //Build up a row with two columns
        QList<QStandardItem*> column_fields;
        column_fields.append(new QStandardItem(QString(current_call->address().c_str())));
        column_fields.append(new QStandardItem(QString(current_call->function().c_str())));

        //Append the row
        m_callstack_model.appendRow(column_fields);
    }

    //Resize the left column to fit the contents in
    ui->tableCallstack->resizeColumnToContents(0);
}

void process_window::__update_process_status()
{
    pw::process_status stat;
    stat = m_process->GetProcessStatus();

    std::string str;

    for (size_t i = 0; i < stat.size(); ++i)
    {
        str.append(stat[i]);
        str.append("\n");
    }
    //ui->lblProcessStatus->setText(QString(str.c_str()));
    ui->txtProcessStatus->appendPlainText(QString(str.c_str()));
}

void process_window::__update_window_title()
{
    std::string window_title = pw::stringutils::format("%s (%s)", m_process->pid_str().c_str(), m_process->started_as().c_str());
    this->setWindowTitle(QString(window_title.c_str()));
}
