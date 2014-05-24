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

#ifndef PW_PROCESS_WINDOW_H
#define PW_PROCESS_WINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>

#include "process.h"

namespace Ui
{
class process_window;
}

/*!
 * \brief The window that is shown when a user double clicks a process, this window will provide details
 *        on the clicked process.
 *
 * \author Swen Kooij
 */
class process_window : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Initializes a new instance of the process_window class with the specified parent.
     *
     * \param parent The parent widget of this window.
     */
    explicit process_window(QWidget *parent = 0);

    /*!
     * \brief Sets the process that this window is displaying.
     *
     * \param proc A shared pointer to an instance of the pw::process class,
     *             representing the process this window is displaying.
     */
    void set_process(pw::process_ptr proc);

    /*!
     * \brief Destructor, cleans up allocated resources.
     */
    ~process_window();

private:
     //Updates the title of this window with the current pid, and start path.
     void __update_window_title();

     //Updates the call stack for the current process.
     void __update_callstack();

     //Updates the process status
     void __update_process_status();

     //Prepares the list view of the callstack for a refresh
     void __setup_callstack_table();

private:
    //Provides access to the components within this window.
    Ui::process_window *ui;

    //The underlying process that this window is displaying.
    pw::process_ptr m_process;

    //Model for the list view of call stack items
    QStandardItemModel m_callstack_model;
};

#endif // PW_PROCESS_WINDOW_H
