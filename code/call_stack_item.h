#ifndef PW_CALL_STACK_ITEM_H
#define PW_CALL_STACK_ITEM_H

#include <string>
#include <boost/shared_ptr.hpp>
#include <vector>
namespace pw
{

/*!
 * \brief Represents an item in a callstack.
 *
 * \author Swen Kooij
 */
class call_stack_item
{
private:
    //Re-declared at the bottom of the class for public usage.
    typedef boost::shared_ptr<call_stack_item> call_stack_item_ptr;

public:
    /*!
     * \brief Initializes a new instance of the call_stack_item class.
     */
    call_stack_item();

    /*!
     * \brief Initializes a new instance of the call_stack_item class with the
     *        specified call address and function name.
     *
     * \param address  The address of this call.
     * \param function The name of the object of this call.
     */
    call_stack_item(const std::string &address, const std::string &function);

    /*!
     * \brief Parses the specified line, from a /proc/<pid>/stack file into
     *        an instance of the call_stack_item class.
     *
     * \param proc_stack_line A line from a /proc/<pid>/stack file to parse
     *                        into an instance of the call_stack_item class.
     *
     * \return A shared pointer to an instance of the call_stack_item class. An invalid
     *         shared pointer is returned when parsing failed.
     */
    static call_stack_item_ptr parse(const std::string &proc_stack_line);

private:
    //The address of this call.l
    std::string m_address;

    //The function that this call represents.
    std::string m_function;
};

/*!
 * \brief A shared pointer to an instance of the call_stack_item class.
 */
typedef boost::shared_ptr<call_stack_item> call_stack_item_ptr;

/*!
 * \brief A vector of shared pointers to call_stack_item class instances.
 */
typedef std::vector<call_stack_item_ptr> call_stack;

} // namespace pw

#endif // PW_CALL_STACK_ITEM_H
