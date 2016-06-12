#include "chlog/Logging.hpp"

namespace chlog
{

LogHandler logger(6);

chlog::Input& critical = *logger.get_inputs()[0].get();
chlog::Input& error    = *logger.get_inputs()[1].get();
chlog::Input& warning  = *logger.get_inputs()[2].get();
chlog::Input& notice   = *logger.get_inputs()[3].get();
chlog::Input& info     = *logger.get_inputs()[4].get();
chlog::Input& debug    = *logger.get_inputs()[5].get();

} // namespace chlog
