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
