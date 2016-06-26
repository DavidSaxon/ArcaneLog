#include "arcanelog/LogHandler.hpp"

#include <arcanecore/base/Exceptions.hpp>

#include "arcanelog/AbstractOutput.hpp"
#include "arcanelog/Input.hpp"

namespace arclog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogHandler::LogHandler()
{
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

LogHandler::~LogHandler()
{
    // do nothing -- required for using std::unique_ptr with forward
    // declarations.
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

arclog::Input* LogHandler::vend_input(const arclog::Profile& profile)
{
    std::unique_ptr<Input> input(new Input(this, profile));
    arclog::Input* ptr = input.get();
    m_inputs.push_back(std::move(input));
    return ptr;
}

const LogHandler::OutputVector& LogHandler::get_outputs() const
{
    return m_outputs;
}

arclog::AbstractOutput* LogHandler::add_output(arclog::AbstractOutput* output)
{
    // check that we're not already holding the output
    ARC_FOR_EACH(it, m_outputs)
    {
        if(it->get() == output)
        {
            throw arc::ex::ValueError(
                "LogHandler already contains a pointer to the given output.");
        }
    }

    // add with a unique pointer
    std::unique_ptr<AbstractOutput> out(output);
    m_outputs.push_back(std::move(out));

    return output;
}

bool LogHandler::remove_output(arclog::AbstractOutput* output)
{
    bool removed = false;
    OutputVector::iterator it;
    for(it = m_outputs.begin(); it != m_outputs.end();)
    {
        if(it->get() == output)
        {
            it = m_outputs.erase(it);
            removed = true;
        }
        else
        {
            ++it;
        }
    }

    return removed;
}

} // namespace arclog
