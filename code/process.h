#ifndef PROCESS_H
#define PROCESS_H

namespace pw
{

/*!
 * \brief Represents a process on the current system.
 *
 * \author Swen Kooij
 */
class process
{
public:
    /*!
     * \brief Initializes a new instance of the process class with the specified process identifier.
     *
     * \param pid The process identifier, this is an unique number that identifies a single process.
     */
    process(size_t pid);
};

} // namespace pw

#endif // PROCESS_H
