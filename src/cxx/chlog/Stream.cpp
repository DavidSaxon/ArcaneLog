#include "chlog/Stream.hpp"

#include <sstream>

// TODO: REMOVE ME
#include <iostream>

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

    //-------------------------PUBLIC MEMBER FUNCTIONS--------------------------

    virtual int sync()
    {
        // TODO: clear and do nothing if the stream is disabled

        // TODO: apply prefix

        // TODO apply post fix

        // TODO: send parent Logger

        std::cout << str();
        str("");
        std::cout.flush();
        return 0;
    }
};

//------------------------------------------------------------------------------
//                                   DESTRUCTOR
//------------------------------------------------------------------------------

Stream::~Stream()
{
    delete m_buffer;
}

//------------------------------------------------------------------------------
//                             PROTECTED CONSTRUCTOR
//------------------------------------------------------------------------------

Stream::Stream(chaos::uint32 verbosity)
    :
    std::ostream(new StreamBuffer()),
    m_buffer    (static_cast<StreamBuffer*>(rdbuf())),
    m_verbosity (verbosity)
{
}

} // namespace chlog
