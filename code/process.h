#ifndef PROCESS_H
#define PROCESS_H

#include <stdlib.h>
#include <boost/shared_ptr.hpp>
#include <QString>

namespace pw
{

/*!
 * \brief Represents a process on the current system.
 *
 * \author Swen Kooij
 */
class process
{
public:
    /*!
     * \brief Initializes a new instance of the process class with the specified process identifier.
     *
     * \param pid The process identifier, this is an unique number that identifies a single process.
     */
    process(size_t pid);

    /*!
     * \brief Gets the unique identifier of this process.
     *
     * \return The unique identifier of this process.
     */
    size_t pid();

    /*!
     * \brief Gets the unique identifier of this process as a string.
     *
     * \return The unique identifier of this process as a string.
     */
    QString pid_str();

    /*!
     * \brief Gets the command that made the process start.
     *
     * \return The command that made the process start.
     */
    QString started_as();

private:
    //Builds the path the cmdline file for this process.
    QString __build_cmd_line();

private:
    //The unique process identifier.
    size_t m_pid;
};

/*!
 * \brief A shared pointer to an instance of the process class.
 */
typedef boost::shared_ptr<process> process_ptr;

} // namespace pw

#endif // PROCESS_H
