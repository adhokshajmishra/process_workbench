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

#ifndef PW_PROCESS_H
#define PW_PROCESS_H

#include <stdlib.h>
#include <boost/shared_ptr.hpp>
#include <string>

#include "call_stack_item.h"

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

    /*!
     * \brief Gets the current call stack of this process.
     *
     * \return A vector of shared pointers to instances of the call_stack_item
     *         class. Representing the current call stack of this process.
     */
    call_stack callstack();

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
