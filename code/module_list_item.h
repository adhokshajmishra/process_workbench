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

#ifndef PW_MODULE_LIST_ITEM_H
#define PW_MODULE_LIST_ITEM_H

#include <string>
#include <boost/shared_ptr.hpp>
#include <vector>

namespace pw
{

class module_list_item
{
private:
    typedef boost::shared_ptr<module_list_item> module_list_item_ptr;
public:
    module_list_item();
    module_list_item();
};  // class module_list_item

}   // namespace pw

#endif // PW_MODULE_LIST_ITEM_H
