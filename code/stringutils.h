#ifndef PW_STRINGUTILS_H
#define PW_STRINGUTILS_H

#include <string>
#include <cstdarg>

namespace pw
{

/*!
 * \brief Simple utility class for working with strings.
 *
 * \author Swen Kooij
 */
class stringutils
{
public:
    /*!
     * \brief Simple C++ style wrapper for snprintf, returns an std::string instead
     *        of outputting to a references buffer.
     *
     * \param fmt The format string.
     *
     * \return The formatted string.
     */
    static std::string format(const char *fmt, ...);

private:
    //Explicit private constructor to prevent construction.
    stringutils() {}
};

} // namespace pw

#endif // PW_STRINGUTILS_H
