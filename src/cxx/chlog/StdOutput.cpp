#include "chlog/StdOutput.hpp"

#include <iostream>

namespace chlog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StdOutput::StdOutput()
    :
    AbstractOutput()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StdOutput::write(
        chlog::Verbosity verbosity,
        const chlog::Profile& profile,
        const chaos::str::UTF8String& message)
{
    // build the message prefix and suffix
    chaos::str::UTF8String prefix;
    // add the app name and version to the prefix (if required)
    if(!profile.app_name.is_empty())
    {
        prefix = profile.app_name;
    }
    if(!profile.app_version.is_empty())
    {
        if(!prefix.is_empty())
        {
            prefix += "-";
        }
        prefix += profile.app_version;
    }
    if(!prefix.is_empty())
    {
        prefix = chaos::str::UTF8String("{") + prefix + "} - ";
    }
    // add the verbosity level to the prefix
    switch(verbosity)
    {
        case chlog::VERBOSITY_CRITICAL:
            prefix += "[CRITICAL]: ";
            break;
        case chlog::VERBOSITY_ERROR:
            prefix += "[ERROR]: ";
            break;
        case chlog::VERBOSITY_WARNING:
            prefix += "[WARNING]: ";
            break;
        case chlog::VERBOSITY_NOTICE:
            prefix += "[NOTICE]: ";
            break;
        case chlog::VERBOSITY_INFO:
            prefix += "[INFO]: ";
            break;
        case chlog::VERBOSITY_DEBUG:
            prefix += "[DEBUG]: ";
            break;
    }

    // TODO: ANSI


    // TODO: pick stream first
    if(verbosity < 4)
    {
        std::cerr << prefix << message;
        std::cerr.flush();
    }
    else
    {
        std::cout << prefix << message;
        std::cout.flush();
    }
}

} // namespace chlog
