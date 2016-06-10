#include <chaoscore/test/ChaosTest.hpp>

CHAOS_TEST_MODULE(Logging)

#include <chlog/Logging.hpp>

namespace
{

CHAOS_TEST_UNIT(logging)
{
    chlog::notice("Hello");
    chlog::notice("World");
}

} // namespace
