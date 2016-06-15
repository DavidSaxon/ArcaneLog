/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_INPUT_HPP_
#define CHAOSLOG_INPUT_HPP_

#include <chaoscore/base/Preproc.hpp>

#include "chlog/Stream.hpp"

namespace chlog
{

/*!
 * \brief TODO
 */
class Input
{
private:

    CHAOS_DISALLOW_COPY_AND_ASSIGN(Input);

    //--------------------------------------------------------------------------
    //                                  FRIENDS
    //--------------------------------------------------------------------------

    friend class LogHandler;

public:

    //--------------------------------------------------------------------------
    //                             PUBLIC ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO
     */
    chlog::Stream critical;
    /*!
     * \brief TODO
     */
    chlog::Stream error;
    /*!
     * \brief TODO
     */
    chlog::Stream warning;
    /*!
     * \brief TODO
     */
    chlog::Stream notice;
    /*!
     * \brief TODO
     */
    chlog::Stream info;
    /*!
     * \brief TODO
     */
    chlog::Stream debug;

protected:

    //--------------------------------------------------------------------------
    //                           PROTECTED CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO
     */
    Input(chlog::LogHandler* log_handler, const chlog::Profile& profile);
};

// /*!
//  * \brief TODO
//  */
// class Input : public std::ostream
// {
// private:

//     //--------------------------------------------------------------------------
//     //                                  FRIENDS
//     //--------------------------------------------------------------------------

//     friend class LogHandler;

//     //--------------------------------------------------------------------------
//     //                            FORWARD DECLARATIONS
//     //--------------------------------------------------------------------------

//     class StreamBuffer;

// public:

//     //--------------------------------------------------------------------------
//     //                                 DESTRUCTOR
//     //--------------------------------------------------------------------------

//     ~Input();

// protected:

//     //--------------------------------------------------------------------------
//     //                           PROTECTED CONSTRUCTOR
//     //--------------------------------------------------------------------------

//     /*!
//      * \brief TODO
//      */
//     Input(
//             chlog::LogHandler* log_handler,
//             chlog::Verbosity verbosity,
//             const chlog::Profile& profile);

// private:

//     //--------------------------------------------------------------------------
//     //                             PRIVATE ATTRIBUTES
//     //--------------------------------------------------------------------------

//     /*!
//      * \brief The internal buffer of this input.
//      */
//     chlog::Input::StreamBuffer* m_buffer;
// };

} // namespace chlog

#endif
