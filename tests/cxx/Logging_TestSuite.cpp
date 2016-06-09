#include <chaoscore/test/ChaosTest.hpp>

CHAOS_TEST_MODULE(Logging)

#include <chlog/Logging.hpp>

namespace
{

CHAOS_TEST_UNIT(logging)
{
    CHAOS_TEST_MESSAGE("Development Prototyping...");

    chlog::log.print("Hello");
    chlog::log.print("World");
}

} // namespace
