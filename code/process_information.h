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

#ifndef PROCESS_INFORMATION_H
#define PROCESS_INFORMATION_H

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
};
}

#endif // PROCESS_INFORMATION_H
