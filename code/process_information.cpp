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

#include "process_information.h"
#include "error_codes.h"

#include <fstream>
#include <iostream>
#include <string>

#include <QString>

#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

namespace pw
{
process_information::process_information(const int &pid)
{
    this->pid = pid;
}

int process_information::call_stack(QStringList &stack)
{
    std::ifstream file;
    QString fname = "/proc";
    std::string s = boost::lexical_cast<std::string>(this->pid);
    fname.append(s.c_str());
    fname.append("/stack");

    file.open(fname.toStdString().c_str());

    if (!file.is_open())
    {
        return ERROR_FILE_NOT_OPENED;
    }

    std::string line;

    while (getline(file, line))
    {

        stack.append(QString(line.c_str()));
    }

    return ERROR_SUCESS;
}

int process_information::loaded_modules(QStringList &modules)
{
    // list of modules is present in /proc/<pid>/maps
    // modules are filtered using regular expression (they will contain .so somewhere in
    // name)string line;
    // the code is not perfect. Edits required.

    std::ifstream file;
    QString fname = "/proc";
    std::string s = boost::lexical_cast<std::string>(this->pid);
    fname.append(s.c_str());
    fname.append("/maps");

    file.open(fname.toStdString().c_str());

    if (!file.is_open())
    {
        return ERROR_FILE_NOT_OPENED;
    }

    std::string line;

    while (getline(file, line))
    {
        boost::regex module_regex("\\.(so)");

        boost::match_results<std::string::const_iterator> result;

        if (boost::regex_match(line, result, module_regex, boost::match_default))
        {
            // match found.
            // index [0]-[73] contains address range and white spaces.
            std::string module_path;
            module_path.append(line.begin() + 73, line.end());
            modules.append(QString(module_path.c_str()));
        }
    }

    return ERROR_SUCESS;
}
} //namespace pw
