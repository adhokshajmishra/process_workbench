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

#include <QFile>
#include <QByteArray>

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

QString process::pid_str()
{
    return QString("%1").arg(m_pid);
}

QString process::started_as()
{
    QFile cmdline_file(__build_cmd_line());
    if(!cmdline_file.exists())
        return "";

    if(!cmdline_file.open(QIODevice::ReadOnly))
        return "";

    QByteArray contents_raw = cmdline_file.readAll();
    QString contents(contents_raw);

    return contents;
}

QString process::__build_cmd_line()
{
    return QString("/proc/%1/cmdline").arg(m_pid);
}

} // namespace pw
