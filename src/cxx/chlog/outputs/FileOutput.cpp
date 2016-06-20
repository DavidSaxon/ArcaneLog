#include "chlog/outputs/FileOutput.hpp"

#include <chaoscore/io/sys/FileSystemOperations.hpp>

namespace chlog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

FileOutput::FileOutput(
        chaos::io::sys::Path& path,
        bool open_now,
        chlog::Verbosity verbosity_level)
    :
    AbstractOutput(verbosity_level),
    m_path        (path),
    m_opened_once (false)
{
    if(open_now)
    {
        set_enabled(true);
    }
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void FileOutput::set_enabled(bool enabled)
{
    // open?
    if(enabled && !m_writer.is_open())
    {
        // does the file handle need to be opened for the first time?
        if(!m_opened_once)
        {
            // validate the path first
            chaos::io::sys::validate(m_path);

            // set up the writer
            m_writer.set_path(m_path);
            m_writer.set_encoding(chaos::io::sys::FileHandle::ENCODING_UTF8);
            m_writer.set_open_mode(chaos::io::sys::FileWriter::OPEN_TRUNCATE);
            m_writer.open();

            m_opened_once = true;
        }
        else
        {
            // open in append mode
            m_writer.set_open_mode(chaos::io::sys::FileWriter::OPEN_APPEND);
            m_writer.open();
        }
    }
    // close?
    else if(!enabled && m_writer.is_open())
    {
        m_writer.close();
    }

    // super call
    AbstractOutput::set_enabled(enabled);
}

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
