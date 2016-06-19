#include <chaoscore/test/ChaosTest.hpp>

CHAOS_TEST_MODULE(Logging)

#include <chaoscore/io/sys/FileSystemOperations.hpp>

#include <chlog/Logging.hpp>
#include <chlog/outputs/FileOutput.hpp>
#include <chlog/outputs/StdOutput.hpp>

namespace
{

// static chlog::LogHandler this_logger;

static chlog::Profile log_profile("ChaosLog", "0.0.1");
static chlog::Input* logger = chlog::default_handler.vend_input(log_profile);

static chlog::Profile log_profile2("ValgrindPlugin", "1.4.27");
static chlog::Input* logger2 = chlog::default_handler.vend_input(log_profile2);


CHAOS_TEST_UNIT(logging)
{
    // set up the logger
    chlog::default_handler.add_output(
        new chlog::StdOutput(chlog::VERBOSITY_DEBUG));
    chaos::io::sys::Path log_path;
    log_path << "logs" << "log.txt";
    chaos::io::sys::validate(log_path);
    chlog::default_handler.add_output(
        new chlog::FileOutput(log_path, chlog::VERBOSITY_DEBUG));


    logger->critical << "Hello" << std::endl;
    logger2->error << "World" << std::endl;
    logger->warning << 1337 << std::endl;
    logger->notice << chaos::str::UTF8String("aל∑") << std::endl;
    logger2->info << 12.4F << std::endl;
    logger->debug << "<EOF>" << std::endl;

    logger2->critical << "Hello" << std::endl;
    logger->error << "World" << std::endl;
    logger->warning << 1337 << std::endl;
    logger->notice << chaos::str::UTF8String("aל∑") << std::endl;
    logger->info << 12.4F << std::endl;
    logger2->debug << "<EOF>" << std::endl;
}

} // namespace
