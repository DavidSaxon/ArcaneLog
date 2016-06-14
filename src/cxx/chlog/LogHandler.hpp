/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_LOGHANDLER_HPP_
#define CHAOSLOG_LOGHANDLER_HPP_

#include <map>
#include <memory>
#include <vector>

#include "chlog/Profile.hpp"
#include "chlog/Verbosity.hpp"

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
     */
    LogHandler();

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    ~LogHandler();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO:
     */
    chlog::Input& vend_input(
            chlog::Verbosity verbosity,
            const chlog::Profile& profile = chlog::Profile());

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

    /*!
     * \brief Removes the given output from this LogHandler.
     *
     * \param output The pointer to the output to remove.
     *
     * \returns Whether the output exists in this log handler to be removed or
     *          not.
     */
    bool remove_output(chlog::AbstractOutput* output);

private:

    //--------------------------------------------------------------------------
    //                             PRIVATE ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief The input streams attached to this LogHandler.
     */
    InputVector m_inputs;

    /*!
     * \brief The output writers of this log LogHandler.
     */
    OutputVector m_outputs;
};

} // namespace chlog

#endif
