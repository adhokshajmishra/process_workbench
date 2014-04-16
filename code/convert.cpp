#include "convert.h"

#include <boost/lexical_cast.hpp>

namespace pw
{

std::string convert::to_string(size_t value)
{
    return boost::lexical_cast<std::string>(value);
}

int convert::to_int(const std::string &value, int def /* = -1 */)
{
    try
    {
        return boost::lexical_cast<int>(value);
    }
    catch(boost::bad_lexical_cast)
    {
        return def;
    }
}

} // namespace pw
