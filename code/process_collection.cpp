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

#include "process_collection.h"
#include "types.h"
#include "fileutils.h"
#include "convert.h"

#include <cctype>

namespace pw
{

process_collection::process_collection() :
    m_processes()
{
}

process_collection::process_collection(process_vector &processes) :
    m_processes(processes)
{
}

process_collection process_collection::get_all()
{
    //Get all processes from /proc
    string_vector pids = fileutils::get_dir_dirs("/proc");

    //We'll store the processes we found in here..
    process_vector processes;

    //Iterate over the processes...
    for(int i = 0; i < pids.size(); ++i)
    {
        //If the current name is not a digit, then it's not a pid
        if(pids[i].size() <= 0)
            continue;

        //Attempt to convert the string to a size_t
        int current_pid = convert::to_int(pids[i]);
        if(current_pid <= 0)
            continue;

        //Initialize a new instance of the process class with this pid
        process_ptr proc (new process((size_t)current_pid));
        processes.push_back(proc);
    }

    //Return the list processes
    return process_collection(processes);
}

size_t process_collection::count() const
{
    return (size_t)m_processes.size();
}

process_ptr process_collection::get_at(size_t index) const
{
    //Prevent going out of bounds
    size_t max_index = this->count() - 1;
    if(index > max_index)
        return process_ptr();

    return m_processes[index];
}

} // namespace pw
