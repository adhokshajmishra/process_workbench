/*
 * Process Analyzer is a small tool to analyze processes on standard LINUX
 * platform.
 *
 * Copyright (c) Adhokshaj Mishra, Swen Kooij
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
