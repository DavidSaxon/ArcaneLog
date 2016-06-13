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

/*!
 * \brief TODO:
 */
class AbstractOutput
{
private:

    CHAOS_DISALLOW_COPY_AND_ASSIGN(AbstractOutput);

public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief TODO:
     */
    AbstractOutput();

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
     * \brief TODO:
     */
    virtual void write(
            chlog::Verbosity verbosity,
            const chlog::Profile& profile,
            const chaos::str::UTF8String& message) = 0;
};

} // namespace chlog

#endif
