/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_LOGHANDLER_HPP_
#define CHAOSLOG_LOGHANDLER_HPP_

#include <memory>
#include <vector>

#include "chlog/Stream.hpp"

namespace chlog
{

class AbstractOutput;

/*!
 * \brief TODO:
 */
class LogHandler
{
public:

    //--------------------------------------------------------------------------
    //                              TYPE DEFINITIONS
    //--------------------------------------------------------------------------

    // TODO: change stream to input
    typedef std::vector<std::unique_ptr<AbstractOutput>> OutputVector;

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief Creates a new Logging object.
     *
     * \param stream_count The number of input streams associated with this
     *                     logger, each stream will have an incremental
     *                     verbosity value.
     */
    LogHandler(std::size_t stream_count);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~LogHandler();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Returns the input streams of this log handler, in order of their
     *        verbosity.
     */
    const std::vector<std::unique_ptr<Stream>>& get_streams() const;

    const OutputVector& get_output() const;

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The input streams of this log handler, in order of their
     *        verbosity.
     */
    std::vector<std::unique_ptr<Stream>> m_streams;

    /*!
     * \brief The output writers of this log handler.
     */
    std::vector<std::unique_ptr<AbstractOutput>> m_output;
};

} // namespace chlog

#endif
