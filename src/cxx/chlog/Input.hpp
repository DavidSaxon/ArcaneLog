/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_INPUT_HPP_
#define CHAOSLOG_INPUT_HPP_

#include <memory>

#include <chaoscore/base/str/UTF8String.hpp>

#include "chlog/Profile.hpp"
#include "chlog/Verbosity.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class LogHandler;

/*!
 * \brief TODO
 */
class Input : public std::ostream
{
private:

    //--------------------------------------------------------------------------
    //                                  FRIENDS
    //--------------------------------------------------------------------------

    friend class LogHandler;

    //--------------------------------------------------------------------------
    //                            FORWARD DECLARATIONS
    //--------------------------------------------------------------------------

    class StreamBuffer;

public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Input();

protected:

    //--------------------------------------------------------------------------
    //                           PROTECTED CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO
     */
    Input(
            chlog::LogHandler* log_handler,
            chlog::Verbosity verbosity,
            const chlog::Profile& profile);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The internal buffer of this input.
     */
    chlog::Input::StreamBuffer* m_buffer;
};

} // namespace chlog

#endif
