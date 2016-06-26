#include "arcanelog/AbstractOutput.hpp"

namespace arclog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

AbstractOutput::AbstractOutput(arclog::Verbosity verbosity_level)
    :
    m_enabled        (true),
    m_verbosity_level(verbosity_level)
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

bool AbstractOutput::is_enabled() const
{
    return m_enabled;
}

void AbstractOutput::set_enabled(bool enabled)
{
    m_enabled = enabled;
}

arclog::Verbosity AbstractOutput::get_verbosity_level() const
{
    return m_verbosity_level;
}

void AbstractOutput::set_verbosity_level(arclog::Verbosity verbosity_level)
{
    m_verbosity_level = verbosity_level;
}


} // namespace arclog
