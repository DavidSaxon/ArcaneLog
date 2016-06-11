#include "chlog/Logging.hpp"

namespace chlog
{

LogHandler logger(6);

Stream& critical = *logger.get_streams()[0].get();
Stream& error    = *logger.get_streams()[1].get();
Stream& warning  = *logger.get_streams()[2].get();
Stream& notice   = *logger.get_streams()[3].get();
Stream& info     = *logger.get_streams()[4].get();
Stream& debug    = *logger.get_streams()[5].get();

} // namespace chlog
