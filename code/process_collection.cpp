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
