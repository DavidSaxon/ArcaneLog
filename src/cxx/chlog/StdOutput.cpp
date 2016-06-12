#include "chlog/StdOutput.hpp"

#include <iostream>

namespace chlog
{

//------------------------------------------------------------------------------
//                                  CONSTRUCTOR
//------------------------------------------------------------------------------

StdOutput::StdOutput()
    :
    AbstractOutput()
{
}

//------------------------------------------------------------------------------
//                            PUBLIC MEMBER FUNCTIONS
//------------------------------------------------------------------------------

void StdOutput::write(
        chaos::uint32 verbosity_level,
        const chaos::str::UTF8String& message)
{
    std::cout << verbosity_level << " :: " << message;
    std::cout.flush();
}

} // namespace chlog
