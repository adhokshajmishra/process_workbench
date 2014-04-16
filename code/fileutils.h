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

#ifndef PW_FILEUTILS_H
#define PW_FILEUTILS_H

#include <string>
#include <vector>

#include "types.h"

namespace pw
{

/*!
 * \brief Provides simple and easy acess to the filesystem.
 *
 * \author Swen Kooij
 */
class fileutils
{
public:
    /*!
     * \brief Checks if the specified path to a directory or file exists.
     *
     * \param path The path to check the existence of.
     *
     * \return True when the specified path exists and false when it doesn't.
     */
    static bool exists(const std::string &path);

    /*!
     * \brief Reads the entire, specified file into a string and returns it.
     *
     * \param path The path to the file to read from.
     *
     * \return A string containing the contents of the specified file. An empty
     *         string is returned when the file didn't exists or could
     *         not be read.
     */
    static std::string read_file_all(const std::string &path);

    /*!
     * \brief Reads the entire, specified file into a vector of strings, where
     *        each item is a line.
     *
     * \param path The path to the file to read from.
     *
     * \return A vector of strings, where each item is a line. An empty vector
     *         is returned when the specified file didn't exists, or could not be read.
     */
    static string_vector read_file_lines(const std::string &path);

    /*!
     * \brief Combines the specified base path, and relative path into a single path.
     *
     * \param base_path The base path to append the specified relative path to.
     * \param append    The relative path to append to the specified base path.
     *
     * \return The specified base path, combined with the specified relative path.
     */
    static std::string combine_path(const std::string &base_path, const std::string &append);

    /*!
     * \brief Gets a collection of all directories in the specified directory.
     *
     * \param dir_path The path to get all directories from.
     *
     * \return A vector of strings, where each item, is the name of a directory
     *         within the specified directory. An empty vector is returned
     *         when the specified directory did not exists.
     */
    static string_vector get_dir_dirs(const std::string &dir_path);

    /*!
     * \brief Checks if the specified path is a directory.
     *
     * \param path The path to check of whether it's a directory.
     *
     * \return A boolean indicating whether the specified path is a directory.
     */
    static bool is_directory(const std::string &path);

    /*!
     * \brief Checks if the specified path is a file.
     *
     * \param path The path to check of whether it's a file.
     *
     * \return A boolean indicating whether the specified path is a file.
     */
    static bool is_file(const std::string &path);

private:
    //Explicit private constructor to prevent construction.
    fileutils() {}
};

} // namespace pw

#endif // PW_FILEUTILS_H
