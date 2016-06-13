#include <chaoscore/test/ChaosTest.hpp>

CHAOS_TEST_MODULE(Logging)

#include <chlog/Logging.hpp>

namespace
{

static chlog::LogHandler this_logger;

static chlog::Profile log_profile("ChaosLog", "0.0.1");

chlog::Input& critical =
    this_logger.vend_input(chlog::VERBOSITY_CRITICAL, log_profile);
chlog::Input& error    =
    this_logger.vend_input(chlog::VERBOSITY_ERROR, log_profile);
chlog::Input& warning  =
    this_logger.vend_input(chlog::VERBOSITY_WARNING, log_profile);
chlog::Input& notice   =
    this_logger.vend_input(chlog::VERBOSITY_NOTICE, log_profile);
chlog::Input& info     =
    this_logger.vend_input(chlog::VERBOSITY_INFO, log_profile);
chlog::Input& debug    =
    this_logger.vend_input(chlog::VERBOSITY_DEBUG, log_profile);

CHAOS_TEST_UNIT(logging)
{
    // chlog::critical << "Hello" << std::endl;
    // chlog::error << "World" << std::endl;
    // chlog::warning << 1337 << std::endl;
    // chlog::notice << chaos::str::UTF8String("aל∑") << std::endl;
    // chlog::info << 12.4F << std::endl;
    // chlog::debug << "<EOF>" << std::endl;

    critical << "Hello" << std::endl;
    error << "World" << std::endl;
    warning << 1337 << std::endl;
    notice << chaos::str::UTF8String("aל∑") << std::endl;
    info << 12.4F << std::endl;
    debug << "<EOF>" << std::endl;
}

} // namespace
