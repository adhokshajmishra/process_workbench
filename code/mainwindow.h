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

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>

namespace Ui {
class MainWindow;
}

/*!
 * \brief Represents the main window of this application.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * \brief Initializes a new instance of the MainWindow class
     *
     * \param parent The widget that is the parent of this window.
     */
    explicit MainWindow(QWidget *parent = 0);

    /*!
     * \brief Destructor, cleans up allocated resources.
     */
    ~MainWindow();

private:
    //Sets up the process list, and does the initial refresh
    void __setup_process_list();

    //Refreshes the list with processes.
    void __refresh_process_list();

private slots:
    //Fired when the refresh button is clicked.
    void on_action_Refresh_triggered();

private:
    //Pointer to an instance of this, holds all of happy components
    Ui::MainWindow *ui;

    //Model for the list view of processes..
    QStandardItemModel m_process_model;
};

#endif // MAINWINDOW_H
