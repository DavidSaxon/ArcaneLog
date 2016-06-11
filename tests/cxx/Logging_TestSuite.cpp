#include <chaoscore/test/ChaosTest.hpp>

CHAOS_TEST_MODULE(Logging)

#include <chlog/Logging.hpp>

namespace
{

CHAOS_TEST_UNIT(logging)
{
    chlog::critical << "Hello" << std::endl;
    chlog::error << "World" << std::endl;
    chlog::warning << 1337 << std::endl;
    chlog::notice << chaos::str::UTF8String("aל∑") << std::endl;
    chlog::info << 12.4F << std::endl;
    chlog::debug << "<EOF>" << std::endl;
}

} // namespace
