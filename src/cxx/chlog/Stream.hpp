/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_STREAM_HPP_
#define CHAOSLOG_STREAM_HPP_

#include <memory>

#include <chaoscore/base/str/UTF8String.hpp>

namespace chlog
{

/*!
 * \brief TODO
 */
class Stream : public std::ostream
{
private:

    //--------------------------------------------------------------------------
    //                            FORWARD DECLARATIONS
    //--------------------------------------------------------------------------

    // TODO: can this be moved down?
    class StreamBuffer;

public:

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~Stream();

// TODO: reprotect
// protected:

    //--------------------------------------------------------------------------
    //                           PROTECTED CONSTRUCTOR
    //--------------------------------------------------------------------------

    Stream(chaos::uint32 verbosity);



private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The internal buffer of this stream.
     */
     StreamBuffer* m_buffer;

     /*!
      * \brief The verbosity level of this stream.
      */
    const chaos::uint32 m_verbosity;
};

} // namespace chlog

#endif
