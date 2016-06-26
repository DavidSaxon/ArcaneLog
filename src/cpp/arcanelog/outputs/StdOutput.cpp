#include "arcanelog/outputs/StdOutput.hpp"

#include <iostream>

#include <arcanecore/io/format/ANSI.hpp>

namespace arclog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StdOutput::StdOutput(arclog::Verbosity verbosity_level, UseANSI use_ansi)
    :
    AbstractOutput(verbosity_level),
    m_use_ansi    (use_ansi)
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StdOutput::write(
        arclog::Verbosity verbosity,
        const arclog::Profile& profile,
        const arc::str::UTF8String& message)
{
    // should writing be skipped?
    if(!m_enabled || verbosity > m_verbosity_level)
    {
        return;
    }

    arc::str::UTF8String formatted;
    // add the app name and version to the prefix (if required)
    if(!profile.app_name.is_empty())
    {
        formatted = profile.app_name;
    }
    if(!profile.app_version.is_empty())
    {
        if(!formatted.is_empty())
        {
            formatted += "-";
        }
        formatted += profile.app_version;
    }
    if(!formatted.is_empty())
    {
        formatted = arc::str::UTF8String("{") + formatted + "} - ";
    }
    // add the verbosity level to the prefix, for efficiency evaluate ANSI
    // colour and attributes here too.
    arc::io::format::ANSIColour ansi_colour =
        arc::io::format::ANSI_FG_DEFAULT;
    arc::io::format::ANSIAttribute ansi_attribute =
        arc::io::format::ANSI_ATTR_NONE;
    switch(verbosity)
    {
        case arclog::VERBOSITY_CRITICAL:
        {
            formatted += "[CRITICAL]: ";
            ansi_colour    = arc::io::format::ANSI_FG_RED;
            ansi_attribute = arc::io::format::ANSI_ATTR_BLINK;
            break;
        }
        case arclog::VERBOSITY_ERROR:
        {
            formatted += "[ERROR]: ";
            ansi_colour    = arc::io::format::ANSI_FG_YELLOW;
            ansi_attribute = arc::io::format::ANSI_ATTR_UNDERSCORE;
            break;
        }
        case arclog::VERBOSITY_WARNING:
        {
            formatted += "[WARNING]: ";
            ansi_colour    = arc::io::format::ANSI_FG_LIGHT_YELLOW;
            ansi_attribute = arc::io::format::ANSI_ATTR_BOLD;
            break;
        }
        case arclog::VERBOSITY_NOTICE:
        {
            formatted += "[NOTICE]: ";
            ansi_colour = arc::io::format::ANSI_FG_WHITE;
            break;
        }
        case arclog::VERBOSITY_INFO:
        {
            formatted += "[INFO]: ";
            ansi_colour = arc::io::format::ANSI_FG_GREEN;
            break;
        }
        case arclog::VERBOSITY_DEBUG:
        {
            formatted += "[DEBUG]: ";
            ansi_colour = arc::io::format::ANSI_FG_CYAN;
            break;
        }
    }

    // add the message
    formatted += message;

    // apply ANSI escape sequences?
    bool apply_ansi = false;
    if(m_use_ansi == USEANSI_ALWAYS)
    {
        apply_ansi = true;
    }
#ifndef ARC_OS_WINDOWS
    else if(m_use_ansi == USEANSI_IF_SUPPORTED)
    {
        apply_ansi = true;
    }
#endif

    if(apply_ansi)
    {
        arc::io::format::apply_escape_sequence(
            formatted,
            ansi_colour,
            ansi_attribute
        );
    }

    if(verbosity < 4)
    {
        std::cerr << formatted;
        std::cerr.flush();
    }
    else
    {
        std::cout << formatted;
        std::cout.flush();
    }
}

} // namespace arclog
