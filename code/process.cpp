#include "process.h"
#include "convert.h"
#include "stringutils.h"
#include "fileutils.h"

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

std::string process::__build_cmd_line()
{
    return stringutils::format("/proc/%zu/cmdline", m_pid);
}

} // namespace pw
