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

#ifndef PW_CALL_STACK_ITEM_H
#define PW_CALL_STACK_ITEM_H

#include <string>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace pw
{

/*!
 * \brief Represents an item in a callstack.
 *
 * \author Swen Kooij
 */
class call_stack_item
{
private:
    //Re-declared at the bottom of the class for public usage.
    typedef boost::shared_ptr<call_stack_item> call_stack_item_ptr;

public:
    /*!
     * \brief Initializes a new instance of the call_stack_item class.
     */
    call_stack_item();

    /*!
     * \brief Initializes a new instance of the call_stack_item class with the
     *        specified call address and function name.
     *
     * \param address  The address of this call.
     * \param function The name of the object of this call.
     */
    call_stack_item(const std::string &address, const std::string &function);

    /*!
     * \brief Parses the specified line, from a /proc/<pid>/stack file into
     *        an instance of the call_stack_item class.
     *
     * \param proc_stack_line A line from a /proc/<pid>/stack file to parse
     *                        into an instance of the call_stack_item class.
     *
     * \return A shared pointer to an instance of the call_stack_item class. An invalid
     *         shared pointer is returned when parsing failed.
     */
    static call_stack_item_ptr parse(const std::string &proc_stack_line);

    /*!
     * \brief Gets the memory address of this call.
     *
     * \return The memory address of this call.
     */
    std::string address();

    /*!
     * \brief Gets the function name of this call.
     *
     * \return The function name of this call.
     */
    std::string function();

private:
    //The address of this call.l
    std::string m_address;

    //The function that this call represents.
    std::string m_function;
};

/*!
 * \brief A shared pointer to an instance of the call_stack_item class.
 */
typedef boost::shared_ptr<call_stack_item> call_stack_item_ptr;

/*!
 * \brief A vector of shared pointers to call_stack_item class instances.
 */
typedef std::vector<call_stack_item_ptr> call_stack;

} // namespace pw

#endif // PW_CALL_STACK_ITEM_H
