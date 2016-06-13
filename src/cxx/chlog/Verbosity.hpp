/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSLOG_VERBOSITY_HPP_
#define CHAOSLOG_VERBOSITY_HPP_

namespace chlog
{

/*!
 * \brief TODO:
 */
enum Verbosity
{
    VERBOSITY_CRITICAL = 1UL << 0,
    VERBOSITY_ERROR    = 1UL << 1,
    VERBOSITY_WARNING  = 1UL << 2,
    VERBOSITY_NOTICE   = 1UL << 3,
    VERBOSITY_INFO     = 1UL << 4,
    VERBOSITY_DEBUG    = 1UL << 5
};

} // namespace chlog

#endif
