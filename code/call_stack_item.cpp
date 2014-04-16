#include "call_stack_item.h"

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
    if(proc_stack_line.empty())
        return call_stack_item_ptr();


}

} // namespace pw
