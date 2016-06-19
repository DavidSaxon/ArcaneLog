#include "chlog/outputs/FileOutput.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

FileOutput::FileOutput(
        chaos::io::sys::Path& path,
        chlog::Verbosity verbosity_level)
    :
    AbstractOutput(verbosity_level),
    m_writer      (path)
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void FileOutput::write(
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
    // add the verbosity level to the prefix
    switch(verbosity)
    {
        case chlog::VERBOSITY_CRITICAL:
        {
            formatted += "[CRITICAL]: ";
            break;
        }
        case chlog::VERBOSITY_ERROR:
        {
            formatted += "[ERROR]: ";
            break;
        }
        case chlog::VERBOSITY_WARNING:
        {
            formatted += "[WARNING]: ";
            break;
        }
        case chlog::VERBOSITY_NOTICE:
        {
            formatted += "[NOTICE]: ";
            break;
        }
        case chlog::VERBOSITY_INFO:
        {
            formatted += "[INFO]: ";
            break;
        }
        case chlog::VERBOSITY_DEBUG:
        {
            formatted += "[DEBUG]: ";
            break;
        }
    }

    // add the message to formatted string
    formatted += message;

    // write to the file
    m_writer.write(formatted);
}

} // namespace chlog
