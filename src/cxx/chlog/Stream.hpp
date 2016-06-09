/*!
 * \file
 * \brief TODO
 * \author David Saxon
 */
#ifndef CHAOSLOG_STREAM_HPP_
#define CHAOSLOG_STREAM_HPP_

#include <string>

namespace chlog
{

// TODO:
class Stream
{
public:

    Stream();

    void print(const std::string& message);

private:

    unsigned m_count;
};

} // namespace chlog

#endif
