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

/*!
 * Class to collect and parse process information from /proc/<pid>
 * Author: Adhokshaj Mishra
 *
 * Changelog
 * =========
 *
 * Original: April 16, 2014 Wednesday, India.
 */

#include <QStringList>
#include <QString>

#ifndef PW_PROCESS_INFORMATION_H
#define PW_PROCESS_INFORMATION_H

namespace pw
{
class process_information
{
private:
    int pid;
protected:
public:
    process_information(const int &pid);
    int call_stack(QStringList &stack);
    int loaded_modules(QStringList &modules);
};
} // namespace pw

#endif // PW_PROCESS_INFORMATION_H
