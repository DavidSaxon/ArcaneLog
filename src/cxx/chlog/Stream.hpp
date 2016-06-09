/*!
 * \file
 * \brief TODO
 * \author David Saxon
 */
#ifndef CHAOSLOG_STREAM_HPP_
#define CHAOSLOG_STREAM_HPP_

#include <iostream>

namespace chlog
{

// TODO:
class Stream
{
public:

    Stream()
        :
        count(0)
    {
    }

    void print(const std::string& message)
    {
        std::cout << (count++) << ": " << message << std::endl;
    }

private:

    unsigned count;
};

} // namespace chlog

#endif
