#include "stringutils.h"

#include <cstdio>

namespace pw
{

std::string stringutils::format(const char *fmt, ...)
{
    va_list ap;
    size_t size;
    char result[0x1000];
    size = 0x1000;

    va_start(ap, fmt);
    size = vsnprintf(result, size-1, fmt, ap);
    va_end(ap);

    result[size] = '\0';

    return std::string(result, size);
}

} // namespace pw
