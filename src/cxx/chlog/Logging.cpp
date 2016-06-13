#include "chlog/Logging.hpp"

namespace chlog
{

LogHandler logger;

chlog::Input& critical = logger.vend_input(chlog::VERBOSITY_CRITICAL);
chlog::Input& error    = logger.vend_input(chlog::VERBOSITY_ERROR);
chlog::Input& warning  = logger.vend_input(chlog::VERBOSITY_WARNING);
chlog::Input& notice   = logger.vend_input(chlog::VERBOSITY_NOTICE);
chlog::Input& info     = logger.vend_input(chlog::VERBOSITY_INFO);
chlog::Input& debug    = logger.vend_input(chlog::VERBOSITY_DEBUG);

} // namespace chlog
