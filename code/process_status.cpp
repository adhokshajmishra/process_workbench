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

#include "process_status.h"
#include "stringutils.h"
#include "types.h"
#include "fileutils.h"

#include <QString>
#include <QStringList>

namespace pw
{
ProcessStatus::ProcessStatus(size_t pid)
{
    this->pid = pid;
}

process_status ProcessStatus::GetProcessStatus()
{
    process_status status;
    // read /proc/<pid>/status file
    //Build up the path to the status file and make sure it exists
    std::string path = stringutils::format("/proc/%zu/status", pid);
    if(!fileutils::exists(path))
        return process_status();

    status = fileutils::read_file_lines(path);

    // make it human readable without lookup table.

    for (size_t i = 0; i < status.size(); ++i)
    {
        //
        std::string tmp = status[i];
        QString str(tmp.c_str());
        QStringList list = str.split(":", QString::KeepEmptyParts, Qt::CaseInsensitive);

        if (list[0] == "Name")
        {
            list[0] = "Name:                                ";
        }
        else if (list[0] == "State")
        {
            list[0] = "State:                               ";
        }
        else if (list[0] == "Tgid")
        {
            list[0] = "Thread Group ID:                     ";
        }
        else if (list[0] == "Pid")
        {
            list[0] = "Process ID:                          ";
        }
        else if (list[0] == "PPid")
        {
            list[0] = "Parent Process ID:                   ";
        }
        else if (list[0] == "TracerPid")
        {
            list[0] = "PID of process tracing this process: ";
        }
        else if (list[0] == "Uid")
        {
            list[0] = "UID:                                 ";
        }
        else if (list[0] == "Gid")
        {
            list[0] = "GID:                                 ";
        }
        else if (list[0] == "FDSize")
        {
            list[0] = "No of file descriptor slots:         ";
        }
        else if (list[0] == "Groups")
        {
            list[0] = "Supplementary Group List:            ";
        }
        else if (list[0] == "VmPeak")
        {
            list[0] = "Peak Virtual Memory:                 ";
        }
        else if (list[0] == "VmSize")
        {
            list[0] = "Total Program Size:                  ";
        }
        else if (list[0] == "VmLck")
        {
            list[0] = "Locked Memory:                       ";
        }
        else if (list[0] == "VmHWM")
        {
            list[0] = "Peak Resident Set Size:              ";
        }
        else if (list[0] == "VmRSS")
        {
            list[0] = "Size of Memory Portions:             ";
        }
        else if (list[0] == "VmData")
        {
            list[0] = "Size of data segments:               ";
        }
        else if (list[0] == "VmStk")
        {
            list[0] = "Size of stack segments:              ";
        }
        else if (list[0] == "VmExe")
        {
            list[0] = "Size of text segments:               ";
        }
        else if (list[0] == "VmLib")
        {
            list[0] = "Size of shared library code:         ";
        }
        else if (list[0] == "VmPTE")
        {
            list[0] = "Size of page table entries:          ";
        }
        else if (list[0] == "VmPin")
        {
            list[0] = "Size of pinned pages:                ";
        }
        else if (list[0] == "VmSwap")
        {
            list[0] = "Size of swap usage:                  ";
        }
        else if (list[0] == "Threads")
        {
            list[0] = "No of threads:                       ";
        }
        else if (list[0] == "SigQ")
        {
            list[0] = "Signals queued/max no of queues:     ";
        }
        else if (list[0] == "SigPnd")
        {
            list[0] = "Bitmap of pending signals:           ";
        }
        else if (list[0] == "ShdPnd")
        {
            list[0] = "Bitmap of shared pending signals:    ";
        }
        else if (list[0] == "SigIgn")
        {
            list[0] = "Bitmap of ignored signals:           ";
        }
        else if (list[0] == "SigBlk")
        {
            list[0] = "Bitmap of blocked signals:           ";
        }
        else if (list[0] == "SigCgt")
        {
            list[0] = "Bitmap of cached signals:            ";
        }
        else if (list[0] == "CapInh")
        {
            list[0] = "Bitmap of inheritable capabilities:  ";
        }
        else if (list[0] == "CapPrm")
        {
            list[0] = "Bitmap of permitted capabilities:    ";
        }
        else if (list[0] == "CapEff")
        {
            list[0] = "Bitmap of Effective capabilities:    ";
        }
        else if (list[0] == "CapBnd")
        {
            list[0] = "Bitmap of capabilities bounding set: ";
        }
        else if (list[0] == "Seccomp")
        {
            list[0] = "SECCOMP Mode:                        ";
        }
        else if (list[0] == "Cpus_allowed")
        {
            list[0] = "Mask of allowed CPUs:                ";
        }
        else if (list[0] == "Cpus_allowed_list")
        {
            list[0] = "List of allowed CPUs:                ";
        }
        else if (list[0] == "Mems_allowed")
        {
            list[0] = "Mask of allowed memory nodes:        ";
        }
        else if (list[0] == "Mems_allowed_list")
        {
            list[0] = "List of allowed memory nodes:        ";
        }
        else if (list[0] == "voluntary_ctxt_switches")
        {
            list[0] = "Voluntary context switches:          ";
        }
        else if (list[0] == "nonvoluntary_ctxt_switches")
        {
            list[0] = "Non-voluntary context switches:      ";
        }

        str.clear();
        str = list.join(" ");

        status[i] = str.toStdString();
    }

    return status;
}
}
