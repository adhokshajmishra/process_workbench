#include "process_collection.h"

#include <QDirIterator>
#include <QStringList>
#include <QDir>
#include <cctype>

namespace pw
{

process_collection::process_collection(process_vector &processes) :
    m_processes(processes)
{
}

process_collection process_collection::get_all()
{
    //This directory contains a list of pid's of processes that are currently running..
    //Using a filter we prevent non-pid's from coming into our list..
    QDir proc_dir("/proc");
    proc_dir.setFilter(QDir::Dirs | QDir::NoSymLinks | QDir::NoDotAndDotDot);

    //Get all files/dirs in the /proc directory
    QStringList pids = proc_dir.entryList();

    //We'll store the processes we found in here..
    process_vector processes;

    //Iterate over the processes...
    for(int i = 0; i < pids.count(); ++i)
    {
        //If the current name is not a digit, then it's not a pid
        if(pids[i].length() <= 0)
            continue;

        //Horrible check, but the only alternative is std::stoi just lazy..
        if(!pids[i][0].isDigit())
            continue;

        int current_pid = pids[i].toInt();
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
    return (size_t)m_processes.count();
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
