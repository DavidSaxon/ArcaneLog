#include "chlog/LogHandler.hpp"

#include "chlog/AbstractOutput.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

LogHandler::LogHandler(std::size_t stream_count)
{
    // create the required number of input streams
    for(std::size_t i = 0; i < stream_count; ++i)
    {
        std::unique_ptr<Stream> s(new Stream(i + 1));
        m_streams.push_back(std::move(s));
    }
}

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

LogHandler::~LogHandler()
{

}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

const std::vector<std::unique_ptr<Stream>>& LogHandler::get_streams() const
{
    return m_streams;
}

const LogHandler::OutputVector& LogHandler::get_output() const
{
    return m_output;
}

} // namespace chlog
