/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_STREAM_HPP_
#define CHAOSLOG_STREAM_HPP_

#include <memory>

#include "chlog/Profile.hpp"
#include "chlog/Verbosity.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class LogHandler;
class Input;

/*!
 * \brief TODO:
 */
class Stream : public std::ostream
{
private:

    //--------------------------------------------------------------------------
    //                                  FRIENDS
    //--------------------------------------------------------------------------

    friend class Input;

    //--------------------------------------------------------------------------
    //                            FORWARD DECLARATIONS
    //--------------------------------------------------------------------------

    class StreamBuffer;

public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Stream();

protected:

    //--------------------------------------------------------------------------
    //                           PROTECTED CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO
     */
    Stream(
            chlog::LogHandler* log_handler,
            chlog::Verbosity verbosity,
            const chlog::Profile& profile);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The internal buffer of this stream.
     */
    std::unique_ptr<chlog::Stream::StreamBuffer> m_buffer;
};

} // namespace chlog

#endif
