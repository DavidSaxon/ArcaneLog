/*!
 * \file
 * \brief Generic globals for logging. Most simple programs will only need to
 *        include this file and use the provided log inputs.
 * \author David Saxon
 */
#ifndef CHAOSLOG_LOGGING_HPP_
#define CHAOSLOG_LOGGING_HPP_

#include "chlog/Input.hpp"
#include "chlog/LogHandler.hpp"

/*!
 * \mainpage ChaosLog C++ Documentation.
 *
 * TODO:
 */

/*!
 * \brief Global namespace that contains all ChaosLog functionality.
 */
namespace chlog
{

// TODO: doc
extern chlog::LogHandler default_handler;

} // namespace chlog

#endif
