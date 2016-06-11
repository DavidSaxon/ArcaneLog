/*!
 * \file
 * \brief TODO
 * \author David Saxon
 */
#ifndef CHAOSLOG_LOGGING_HPP_
#define CHAOSLOG_LOGGING_HPP_

#include <chaoscore/base/str/UTF8String.hpp>

#include "chlog/LogHandler.hpp"
#include "chlog/Stream.hpp"

/*!
 * \brief TODO:
 */
namespace chlog
{

// TODO: doc

extern LogHandler logger;

extern Stream& critical;
extern Stream& error;
extern Stream& warning;
extern Stream& notice;
extern Stream& info;
extern Stream& debug;

} // namespace chlog

#endif
