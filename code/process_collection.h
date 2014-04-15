#ifndef PROCESS_COLLECTION_H
#define PROCESS_COLLECTION_H

#include <QVector>

#include "process.h"

namespace pw
{

typedef QVector<process_ptr> process_vector;

/*!
 * \brief Represents a collection of processes, this is some kind of container for process classes.
 *
 * \author Swen Kooij
 */
class process_collection
{
public:
    /*!
     * \brief Gets all processes that are currently running on this system.
     *
     * \return An instance of the process_collection class, containing references
     *         to all processes that are currently running on this system.
     */
    static process_collection get_all();

    /*!
     * \brief Gets the amount of processes this collection contains.
     *
     * \return The amount of processes this collection contains.
     */
    size_t count() const;

    /*!
     * \brief Gets the process at the specified index.
     *
     * \param index The index to get the process at.
     *
     * \return A shared pointer to the process at the specified index, an invalid
     *         shared pointer is returned upon failure.
     */
    process_ptr get_at(size_t index) const;

private:
    /*!
     * \brief Initializes a new instance of the process_collection instance.
     *
     * \param processes A vector of process class instances to initialize this instance with.
     *
     * \note Explictly marked private, initialization may only happen by public static methods.
     */
    process_collection(process_vector &processes);

private:
    //Holds all processes that we currently have loaded.
    process_vector m_processes;
};

} // namespace pw

#endif // PROCESS_COLLECTION_H
