#include "chlog/LogHandler.hpp"

#include <chaoscore/base/Exceptions.hpp>

#include "chlog/AbstractOutput.hpp"
#include "chlog/Input.hpp"
#include "chlog/StdOutput.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogHandler::LogHandler()
{
    // TODO: should this be explicit?
    // initialise with a single std::cout output.
    add_output(new StdOutput());
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

const LogHandler::OutputVector& LogHandler::get_outputs() const
{
    return m_outputs;
}

chlog::Input& LogHandler::vend_input(
        chlog::Verbosity verbosity,
        const chlog::Profile& profile)
{
    // TODO: need to pass verbosity and profile
    std::unique_ptr<Input> input(new Input(this, verbosity, profile));
    chlog::Input& ref = *input.get();
    m_inputs.push_back(std::move(input));
    return ref;
}

void LogHandler::add_output(chlog::AbstractOutput* output)
{
    // check that we're not already holding the output
    CHAOS_FOR_EACH(it, m_outputs)
    {
        if(it->get() == output)
        {
            throw chaos::ex::ValueError(
                "LogHandler already contains a pointer to the given output.");
        }
    }

    // add with a unique pointer
    std::unique_ptr<AbstractOutput> o(output);
    m_outputs.push_back(std::move(o));
}

} // namespace chlog
