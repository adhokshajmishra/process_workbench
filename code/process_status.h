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

#ifndef PW_PROCESS_STATUS_H
#define PW_PROCESS_STATUS_H

#include <vector>
#include <string>
#include <cstdlib>

namespace pw
{
typedef std::vector<std::string> process_status;

class ProcessStatus
{
public:
    // initialize with proper PID
    ProcessStatus(size_t pid);
    process_status GetProcessStatus();
private:
    size_t pid;
};
}

#endif // PW_PROCESS_STATUS_H
