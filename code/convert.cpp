#include "convert.h"

#include <boost/lexical_cast.hpp>

namespace pw
{

std::string convert::to_string(size_t value)
{
    return boost::lexical_cast<std::string>(value);
}

} // namespace pw
