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

#include "process.h"
#include "convert.h"
#include "stringutils.h"
#include "fileutils.h"
#include "process_status.h"

namespace pw
{

process::process(size_t pid) :
    m_pid   (pid)
{
}

size_t process::pid()
{
    return m_pid;
}

std::string process::pid_str()
{
    return convert::to_string(m_pid);
}

std::string process::started_as()
{
    std::string contents = fileutils::read_file_all(__build_cmd_line());
    return contents;
}

process_status process::GetProcessStatus()
{
    //
    ProcessStatus p(this->m_pid);
    return p.GetProcessStatus();
}

call_stack process::callstack()
{
    //Build up the path to the callstack file and make sure it exists
    std::string path = stringutils::format("/proc/%zu/stack", m_pid);
    if(!fileutils::exists(path))
        return call_stack();

    //Read all lines in the file
    string_vector stack_lines = fileutils::read_file_lines(path);

    //Create a new colletion of call_stack_item instances to return
    call_stack return_stack;

    //Iterate over all the stack items
    for(size_t i = 0; i < stack_lines.size(); ++i)
    {
        //Get the current line and attempt to parse it
        std::string current_line = stack_lines[i];
        call_stack_item_ptr call = call_stack_item::parse(current_line);

        //Verify that parsing was a success
        if(!call)
            continue;

        //Add the item to our stack
        return_stack.push_back(call);
    }

    //Return the parsed collection
    return return_stack;
}

std::string process::__build_cmd_line()
{
    return stringutils::format("/proc/%zu/cmdline", m_pid);
}

} // namespace pw
