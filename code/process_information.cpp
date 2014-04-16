/*
 * Author: Adhokshaj Mishra
 */

#include "process_information.h"
#include "error_codes.h"

#include <fstream>
#include <iostream>
#include <string>

#include <QString>

#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

using namespace std;
using namespace boost;

namespace pw
{
process_information::process_information(const int &pid)
{
    this->pid = pid;
}

int process_information::call_stack(QStringList &stack)
{
    ifstream file;
    QString fname = "/proc";
    string s = lexical_cast<string>(this->pid);
    fname.append(s.c_str());
    fname.append("/stack");

    file.open(fname.toStdString().c_str());

    if (!file.is_open())
    {
        return ERROR_FILE_NOT_OPENED;
    }

    string line;

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

    ifstream file;
    QString fname = "/proc";
    string s = lexical_cast<string>(this->pid);
    fname.append(s.c_str());
    fname.append("/maps");

    file.open(fname.toStdString().c_str());

    if (!file.is_open())
    {
        return ERROR_FILE_NOT_OPENED;
    }

    string line;

    while (getline(file, line))
    {
        regex module_regex("\\.(so)");

        match_results<std::string::const_iterator> result;

        if (regex_match(line, result, module_regex, boost::match_default))
        {
            // match found.
            // index [0]-[73] contains address range and white spaces.
            string module_path;
            module_path.append(line.begin() + 73, line.end());
            modules.append(QString(module_path.c_str()));
        }
    }

    return ERROR_SUCESS;
}
}
