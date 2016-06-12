/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_INPUT_HPP_
#define CHAOSLOG_INPUT_HPP_

#include <memory>

#include <chaoscore/base/str/UTF8String.hpp>

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

    // TODO: can this be moved down?
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
            chaos::uint32 verbosity);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The internal buffer of this input.
     */
    chlog::Input::StreamBuffer* m_buffer;

     /*!
      * \brief The verbosity level of this input.
      */
    const chaos::uint32 m_verbosity;
};

} // namespace chlog

#endif
