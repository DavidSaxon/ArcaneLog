#include "chlog/outputs/StdOutput.hpp"

#include <iostream>

#include <chaoscore/io/format/ANSI.hpp>

namespace chlog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StdOutput::StdOutput(chlog::Verbosity verbosity_level, UseANSI use_ansi)
    :
    AbstractOutput(verbosity_level),
    m_use_ansi    (use_ansi)
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
    // should writing be skipped?
    if(!m_enabled || verbosity > m_verbosity_level)
    {
        return;
    }

    chaos::str::UTF8String formatted;
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
        formatted = chaos::str::UTF8String("{") + formatted + "} - ";
    }
    // add the verbosity level to the prefix, for efficiency evaluate ANSI colour
    // and attributes here too.
    chaos::io::format::ANSIColour ansi_colour =
        chaos::io::format::ANSI_FG_DEFAULT;
    chaos::io::format::ANSIAttribute ansi_attribute =
        chaos::io::format::ANSI_ATTR_NONE;
    switch(verbosity)
    {
        case chlog::VERBOSITY_CRITICAL:
            formatted += "[CRITICAL]: ";
            ansi_colour    = chaos::io::format::ANSI_FG_RED;
            ansi_attribute = chaos::io::format::ANSI_ATTR_BLINK;
            break;
        case chlog::VERBOSITY_ERROR:
            formatted += "[ERROR]: ";
            ansi_colour    = chaos::io::format::ANSI_FG_YELLOW;
            ansi_attribute = chaos::io::format::ANSI_ATTR_UNDERSCORE;
            break;
        case chlog::VERBOSITY_WARNING:
            formatted += "[WARNING]: ";
            ansi_colour    = chaos::io::format::ANSI_FG_LIGHT_YELLOW;
            ansi_attribute = chaos::io::format::ANSI_ATTR_BOLD;
            break;
        case chlog::VERBOSITY_NOTICE:
            formatted += "[NOTICE]: ";
            ansi_colour = chaos::io::format::ANSI_FG_WHITE;
            break;
        case chlog::VERBOSITY_INFO:
            formatted += "[INFO]: ";
            ansi_colour = chaos::io::format::ANSI_FG_GREEN;
            break;
        case chlog::VERBOSITY_DEBUG:
            formatted += "[DEBUG]: ";
            ansi_colour = chaos::io::format::ANSI_FG_CYAN;
            break;
    }

    // add the message
    formatted += message;

    // apply ANSI escape sequences?
    bool apply_ansi = false;
    if(m_use_ansi == USEANSI_ALWAYS)
    {
        apply_ansi = true;
    }
#ifndef CHAOS_OS_WINDOWS
    else if(m_use_ansi == USEANSI_IF_SUPPORTED)
    {
        apply_ansi = true;
    }
#endif

    if(apply_ansi)
    {
        chaos::io::format::apply_escape_sequence(
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

} // namespace chlog
