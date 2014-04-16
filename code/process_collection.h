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

#ifndef PW_PROCESS_COLLECTION_H
#define PW_PROCESS_COLLECTION_H

#include "process.h"

#include <vector>

namespace pw
{

/*!
 * \brief A vector of shared pointers to a process class instance.
 */
typedef std::vector<process_ptr> process_vector;

/*!
 * \brief Represents a collection of processes, this is some kind of container for process classes.
 *
 * \author Swen Kooij
 */
class process_collection
{
public:
    /*!
     * \brief Initializes a new instance of the process_collection class.
     */
    process_collection();

    /*!
     * \brief Initializes a new instance of the process_collection instance.
     *
     * \param processes A vector of process class instances to initialize this instance with.
     *
     * \note Explictly marked private, initialization may only happen by public static methods.
     */
    process_collection(process_vector &processes);

    /*!
     * \brief Gets all processes that are currently running on this system.
     *
     * \return An instance of the process_collection class, containing references
     *         to all processes that are currently running on this system.
     */
    static process_collection get_all();

    /*!
     * \brief Gets the amount of processes this collection contains.
     *
     * \return The amount of processes this collection contains.
     */
    size_t count() const;

    /*!
     * \brief Gets the process at the specified index.
     *
     * \param index The index to get the process at.
     *
     * \return A shared pointer to the process at the specified index, an invalid
     *         shared pointer is returned upon failure.
     */
    process_ptr get_at(size_t index) const;

private:
    //Holds all processes that we currently have loaded.
    process_vector m_processes;
};

} // namespace pw

#endif // PW_PROCESS_COLLECTION_H
