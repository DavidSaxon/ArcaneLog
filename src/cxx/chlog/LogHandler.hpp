/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_LOGHANDLER_HPP_
#define CHAOSLOG_LOGHANDLER_HPP_

#include <memory>
#include <vector>

namespace chlog
{

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class AbstractOutput;
class Input;

/*!
 * \brief TODO:
 */
class LogHandler
{
public:

    //--------------------------------------------------------------------------
    //                              TYPE DEFINITIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief std::vector containing unique pointers to chlog::Input objects.
     */
    typedef std::vector<std::unique_ptr<chlog::Input>> InputVector;
    /*!
     * \brief std::vector containing unique pointers to chlog::AbstractOutput
     *        objects.
     */
    typedef std::vector<std::unique_ptr<chlog::AbstractOutput>> OutputVector;

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
    LogHandler(std::size_t input_count);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~LogHandler();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Returns the input streams of this LogHandler, in order of their
     *        verbosity.
     */
    const InputVector& get_inputs() const;

    /*!
     * \brief Returns the output writer of this LogHandler.
     */
    const OutputVector& get_outputs() const;

    /*!
     * \brief Adds a new output writer to this LogHandler.
     *
     * \note The LogHandler will take ownership of the given output writer and
     *       will handle deleting it.
     *
     * \throws chaos::ex::ValueError If this LogHandler already holds a pointer
     *                               to the given writer.
     */
    void add_output(chlog::AbstractOutput* output);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The input streams of this log LogHandler, in order of their
     *        verbosity.
     */
    InputVector m_inputs;

    /*!
     * \brief The output writers of this log LogHandler.
     */
    OutputVector m_outputs;
};

} // namespace chlog

#endif
