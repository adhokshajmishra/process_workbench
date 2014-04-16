#ifndef PW_MAINWINDOW_H
#define PW_MAINWINDOW_H

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

#endif // PW_MAINWINDOW_H
