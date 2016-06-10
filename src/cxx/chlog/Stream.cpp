#include "chlog/Stream.hpp"

#include <iostream>

namespace chlog
{

Stream::Stream()
    :
    m_count(0)
{
}

void Stream::write(const chaos::str::UTF8String& message)
{
    std::cout << m_count << ": " << message << std::endl;
    ++m_count;
}

} // namespace chlog
