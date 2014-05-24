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
