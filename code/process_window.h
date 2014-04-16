#ifndef PW_PROCESS_WINDOW_H
#define PW_PROCESS_WINDOW_H

#include <QMainWindow>

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
     * \brief Destructor, cleans up allocated resources.
     */
    ~process_window();

private:
    //Provides access to the components within this window.
    Ui::process_window *ui;
};

#endif // PW_PROCESS_WINDOW_H
