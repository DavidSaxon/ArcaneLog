#include <arcanecore/test/ArcTest.hpp>

ARC_TEST_MODULE(Logging)

#include <arcanelog/LogHandler.hpp>
#include <arcanelog/Input.hpp>
#include <arcanelog/outputs/FileOutput.hpp>
#include <arcanelog/outputs/StdOutput.hpp>

namespace
{

static arclog::LogHandler test_handler;

static arclog::Profile log_profile("ArcaneLog", "0.0.1");
static arclog::Input* logger = test_handler.vend_input(log_profile);

static arclog::Profile log_profile2("ValgrindPlugin", "1.4.27");
static arclog::Input* logger2 =
    test_handler.vend_input(log_profile2);


ARC_TEST_UNIT(logging)
{
    // set up the logger
    test_handler.add_output(
        new arclog::StdOutput(arclog::VERBOSITY_DEBUG));
    arc::io::sys::Path log_path;
    log_path << "logs" << "log.txt";
    arclog::FileOutput* file_output =
        new arclog::FileOutput(log_path, false, arclog::VERBOSITY_DEBUG);
    test_handler.add_output(file_output);

    logger->critical << "Hello" << std::endl;
    logger2->error << "World" << std::endl;
    logger->warning << 1337 << std::endl;

    file_output->set_enabled(true);

    logger->notice << arc::str::UTF8String("aל∑") << std::endl;
    logger2->info << 12.4F << std::endl;
    logger->debug << "<EOF>" << std::endl;

    file_output->set_enabled(false);

    logger2->critical << "Hello" << std::endl;
    logger->error << "World" << std::endl;
    logger->warning << 1337 << std::endl;

    file_output->set_enabled(true);

    logger->notice << arc::str::UTF8String("aל∑") << std::endl;
    logger->info << 12.4F << std::endl;
    logger2->debug << "<EOF>" << std::endl;
}

} // namespace
