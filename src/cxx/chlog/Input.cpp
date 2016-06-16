#include "chlog/Input.hpp"

#include "chlog/LogHandler.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                             PROTECTED CONSTRUCTOR
//------------------------------------------------------------------------------

Input::Input(chlog::LogHandler* log_handler, const chlog::Profile& profile)
    :
    critical(log_handler, chlog::VERBOSITY_CRITICAL, profile),
    error   (log_handler, chlog::VERBOSITY_ERROR,    profile),
    warning (log_handler, chlog::VERBOSITY_WARNING,  profile),
    notice  (log_handler, chlog::VERBOSITY_NOTICE,   profile),
    info    (log_handler, chlog::VERBOSITY_INFO,     profile),
    debug   (log_handler, chlog::VERBOSITY_DEBUG,    profile)
{
}

} // namespace chlog
