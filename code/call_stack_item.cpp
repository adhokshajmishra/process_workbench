#include "call_stack_item.h"

#include <stdlib.h>

namespace pw
{

call_stack_item::call_stack_item() :
    m_address  (),
    m_function ()
{
}

call_stack_item::call_stack_item(const std::string &address, const std::string &function) :
    m_address  (address),
    m_function (function)
{
}

call_stack_item_ptr call_stack_item::parse(const std::string &proc_stack_line)
{
    //We can't parse empty anyway
    if(proc_stack_line.empty())
        return call_stack_item_ptr();

    //Verify the length, if the string was exactly 5 chars, we would
    //have an empty address and function name
    size_t line_len = proc_stack_line.size();
    if(line_len < 5)
        return call_stack_item_ptr();

    //The first two characters must be [<
    if(proc_stack_line[0] != '[' || proc_stack_line[1] != '<')
        return call_stack_item_ptr();

    //Find the closing brace for the address
    size_t closing_brace_pos = proc_stack_line.find("]");
    if(closing_brace_pos == std::string::npos)
        return call_stack_item_ptr();

    //We have found the ']', let's check if the character before that is
    //a <
    if(proc_stack_line[closing_brace_pos - 1] != '>')
        return call_stack_item_ptr();

    //Extract the address
    std::string address = proc_stack_line.substr(2, closing_brace_pos - 3);

    //After the address, a space should follow
    if(proc_stack_line[closing_brace_pos + 1] != ' ')
        return call_stack_item_ptr(new call_stack_item(address, ""));

    //Extract the function name
    std::string function = proc_stack_line.substr(closing_brace_pos + 2);

    //Return a shared pointer to a new instance with the extracted
    //address and function name
    return call_stack_item_ptr(new call_stack_item(address, function));
}

std::string call_stack_item::address()
{
    return m_address;
}

std::string call_stack_item::function()
{
    return m_function;
}

} // namespace pw
