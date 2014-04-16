#ifndef PW_PROCESS_WINDOW_H
#define PW_PROCESS_WINDOW_H

#include <QMainWindow>

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

private:
    //Provides access to the components within this window.
    Ui::process_window *ui;

    //The underlying process that this window is displaying.
    pw::process_ptr m_process;
};

#endif // PW_PROCESS_WINDOW_H
