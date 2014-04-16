#ifndef PW_PROCESS_H
#define PW_PROCESS_H

#include <stdlib.h>
#include <boost/shared_ptr.hpp>
#include <string>

namespace pw
{

/*!
 * \brief Represents a process on the current system.
 *
 * \note More information on Linux's /proc can be found in the kernel documentation: https://www.kernel.org/doc/Documentation/filesystems/proc.txt
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
    std::string pid_str();

    /*!
     * \brief Gets the command that made the process start.
     *
     * \return The command that made the process start.
     */
    std::string started_as();

private:
    //Builds the path the cmdline file for this process.
    std::string __build_cmd_line();

private:
    //The unique process identifier.
    size_t m_pid;
};

/*!
 * \brief A shared pointer to an instance of the process class.
 */
typedef boost::shared_ptr<process> process_ptr;

} // namespace pw

#endif // PW_PROCESS_H
