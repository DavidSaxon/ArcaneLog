#include "chlog/Logging.hpp"

#include "chlog/Stream.hpp"

namespace chlog
{

//------------------------------------------------------------------------------
//                                 STREAM OBJECT
//------------------------------------------------------------------------------

static Stream g_stream;

//------------------------------------------------------------------------------
//                                   FUNCTIONS
//------------------------------------------------------------------------------

void notice(const chaos::str::UTF8String& message)
{
    g_stream.write(message);
}

} // namespace chlog
