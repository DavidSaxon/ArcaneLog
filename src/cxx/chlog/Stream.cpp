#include "chlog/Stream.hpp"

#include <sstream>

#include "chlog/AbstractOutput.hpp"
#include "chlog/LogHandler.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                                 STREAM BUFFER
//------------------------------------------------------------------------------

/*!
 * \brief Stream buffer which will be used internal to chlog::Stream.
 */
class Stream::StreamBuffer : public std::stringbuf
{
public:

    //-------------------------------CONSTRUCTOR--------------------------------

    StreamBuffer(Stream* stream)
        :
        m_stream(stream)
    {
    }

    //-------------------------PUBLIC MEMBER FUNCTIONS--------------------------

    virtual int sync()
    {
        // TODO: optimise UTF8?
        // send to outputs
        m_stream->send_to_outputs(str().c_str());
        // clear
        str("");

        return 0;
    }

private:

    //----------------------------PRIVATE ATTRIBUTES----------------------------

    /*!
     * \brief The parent Stream of this StreamBuffer.
     */
    Stream* m_stream;
};


//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Stream::~Stream()
{
}

//------------------------------------------------------------------------------
//                             PROTECTED CONSTRUCTOR
//------------------------------------------------------------------------------

Stream::Stream(
        chlog::LogHandler* log_handler,
        chlog::Verbosity verbosity,
        const chlog::Profile& profile)
    :
    std::ostream (new StreamBuffer(this)),
    m_buffer     (static_cast<StreamBuffer*>(rdbuf())),
    m_log_handler(log_handler),
    m_verbosity  (verbosity),
    m_profile    (profile)
{
}

//------------------------------------------------------------------------------
//                           PROTECTED MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void Stream::send_to_outputs(const chaos::str::UTF8String& message)
{
    CHAOS_FOR_EACH(it, (m_log_handler->get_outputs()))
    {
        // TODO: optimise UTF8?
        (*it)->write(m_verbosity, m_profile, message);
    }
}

} // namespace chlog
