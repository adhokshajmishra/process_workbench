#ifndef PW_CONVERT_H
#define PW_CONVERT_H

#include <stdlib.h>
#include <string>

namespace pw
{

/*!
 * \brief Static utility class that helps in converting various data types.
 *
 * \author Swen Kooij
 */
class convert
{
public:
    /*!
     * \brief Converts the specified unsigned integer value to a string.
     *
     * \param value The unsigned integer value to convert to a string.
     *
     * \return The specified input value as a string.
     */
    static std::string to_string(size_t value);

private:
    //This is a static utility class, no construction is allowed.
    convert() {}
};

// namespace pw

#endif // PW_CONVERT_H
