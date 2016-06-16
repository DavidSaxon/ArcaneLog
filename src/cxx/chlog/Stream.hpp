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

    //--------------------------------------------------------------------------
    //                         PROTECTED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Sends the given message to the outputs associated with this
     *        Stream's parent chlog::LogHandler.
     */
    void send_to_outputs(const chaos::str::UTF8String& message);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The internal buffer of this stream.
     */
    std::unique_ptr<chlog::Stream::StreamBuffer> m_buffer;

    /*!
     * \brief Pointer to the chlog::LogHandler object this Stream's parent is
     *        associated with.
     */
    chlog::LogHandler* m_log_handler;

    /*!
     * \brief The verbosity level of this stream.
     */
    const chlog::Verbosity m_verbosity;

    /*!
     * \brief The logging profile of this Stream's parent input.
     */
    const chlog::Profile m_profile;
};

} // namespace chlog

#endif
