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

#ifndef PW_CONVERT_H
#define PW_CONVERT_H

#include <stdlib.h>
#include <string>

namespace pw
{

/*!
 * \brief Static utility class that helps in converting various data types.
 *
 * \author Swen Kooij
 */
class convert
{
public:
    /*!
     * \brief Converts the specified unsigned integer value to a string.
     *
     * \param value The unsigned integer value to convert to a string.
     *
     * \return The specified input value as a string.
     */
    static std::string to_string(size_t value);

    /*!
     * \brief Attempts to convert the specified string value to an integer.
     *
     * \param value     The string to attempt to convert to an integer.
     * \param def       The value to return when the conversion failed.
     *
     * \return The specified string value, as an integer, or the specified
     *         default value when conversion failed.
     */
    static int to_int(const std::string &value, int def = -1);

private:
    //This is a static utility class, no construction is allowed.
    convert() {}
};

} // namespace pw

#endif // PW_CONVERT_H
