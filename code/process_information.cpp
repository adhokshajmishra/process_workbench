/*
 * Author: Adhokshaj Mishra
 */

#include "process_information.h"
#include "error_codes.h"

#include <fstream>
#include <iostream>
#include <QString>
#include <boost/lexical_cast.hpp>

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
}
