/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_ABSTRACTOUTPUT_HPP_
#define CHAOSLOG_ABSTRACTOUTPUT_HPP_

#include <chaoscore/base/str/UTF8String.hpp>

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
        chaos::uint32 verbosity_level,
        const chaos::str::UTF8String& message) = 0;
};

} // namespace chlog

#endif
