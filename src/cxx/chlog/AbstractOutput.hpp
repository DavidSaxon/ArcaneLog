/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_ABSTRACTOUTPUT_HPP_
#define CHAOSLOG_ABSTRACTOUTPUT_HPP_

#include <chaoscore/base/str/UTF8String.hpp>

#include "chlog/Profile.hpp"
#include "chlog/Verbosity.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                              FORWARD DECLARATIONS
//------------------------------------------------------------------------------

class Stream;

/*!
 * \brief TODO:
 */
class AbstractOutput
{
private:

    CHAOS_DISALLOW_COPY_AND_ASSIGN(AbstractOutput);

    //--------------------------------------------------------------------------
    //                                  FRIENDS
    //--------------------------------------------------------------------------

    friend class Stream;

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO:
     */
    AbstractOutput(chlog::Verbosity verbosity_level);

    //--------------------------------------------------------------------------
    //                                 DESTRUCTOR
    //--------------------------------------------------------------------------

    virtual ~AbstractOutput()
    {
    }

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief Returns whether this output is enabled or not.
     */
    bool is_enabled() const;

    /*!
     * \brief Sets whether this output is enabled or not.
     */
    void set_enabled(bool enabled);

    /*!
     * \brief Returns the maximum verbosity level of messages this output will
     *        display.
     */
    chlog::Verbosity get_verbosity_level() const;

    /*!
     * \brief Sets the maximum verbosity level of messages this output will
     *        display.
     */
    void set_verbosity_level(chlog::Verbosity verbosity_level);

protected:

    //--------------------------------------------------------------------------
    //                            PROTECTED ATTRIBUTES
    //--------------------------------------------------------------------------

    /*!
     * \brief Whether this output is enabled or not.
     */
    bool m_enabled;

    /*!
     * \brief The maximum verbosity level of messages this output should
     *        display.
     */
    chlog::Verbosity m_verbosity_level;

    //--------------------------------------------------------------------------
    //                        PROTECETED MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO:
     */
    virtual void write(
            chlog::Verbosity verbosity,
            const chlog::Profile& profile,
            const chaos::str::UTF8String& message) = 0;
};

} // namespace chlog

#endif
