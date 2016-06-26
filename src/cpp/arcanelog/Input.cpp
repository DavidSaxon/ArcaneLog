#include "arcanelog/Input.hpp"

#include "arcanelog/LogHandler.hpp"

namespace arclog
{

//------------------------------------------------------------------------------
//                             PROTECTED CONSTRUCTOR
//------------------------------------------------------------------------------

Input::Input(arclog::LogHandler* log_handler, const arclog::Profile& profile)
    :
    critical(log_handler, arclog::VERBOSITY_CRITICAL, profile),
    error   (log_handler, arclog::VERBOSITY_ERROR,    profile),
    warning (log_handler, arclog::VERBOSITY_WARNING,  profile),
    notice  (log_handler, arclog::VERBOSITY_NOTICE,   profile),
    info    (log_handler, arclog::VERBOSITY_INFO,     profile),
    debug   (log_handler, arclog::VERBOSITY_DEBUG,    profile)
{
}

} // namespace arclog
