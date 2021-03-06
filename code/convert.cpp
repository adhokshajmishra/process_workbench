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
