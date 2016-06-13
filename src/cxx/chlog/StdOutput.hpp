/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_STDOUTPUT_HPP_
#define CHAOSLOG_STDOUTPUT_HPP_

#include "chlog/AbstractOutput.hpp"

namespace chlog
{

/*!
 * \brief TODO:
 */
class StdOutput : public chlog::AbstractOutput
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    StdOutput();

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    // override
    virtual void write(
            chlog::Verbosity verbosity,
            const chlog::Profile& profile,
            const chaos::str::UTF8String& message);
};

} // namespace chlog

#endif
