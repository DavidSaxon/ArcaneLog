/*!
 * \file
 * \author David Saxon
 */
#ifndef CHAOSCORE_TEST_LOGFORMATTER_XMLLOGFORMATTER_HPP_
#define CHAOSCORE_TEST_LOGFORMATTER_XMLLOGFORMATTER_HPP_

// hide from doxygen
#ifndef IN_DOXYGEN

#include "chaoscore/test/log_formatter/AbstractTestLogFormatter.hpp"

namespace chaos
{
namespace test
{
namespace log_formatter
{

/*!
 * \brief Test Log Formatter that writes logs as XML.
 */
class XMLTestLogFormatter : public AbstractTestLogFormatter
{
public:

    //--------------------------------------------------------------------------
    //                                CONSTRUCTOR
    //--------------------------------------------------------------------------

    /*!
     * \brief Creates a new XML Test Log Formatter.
     */
    XMLTestLogFormatter( chaos::uint16 verbosity, std::ostream* stream );

    //--------------------------------------------------------------------------
    //                          PUBLIC MEMBER FUNCTIONS
    //--------------------------------------------------------------------------

    virtual void open_log();

    virtual void close_log(
            chaos::int32  units_passed,
            chaos::int32  units_failed,
            chaos::int32  units_errored,
            chaos::uint64 checks_passed,
            chaos::uint64 checks_failed );

    virtual void open_test(
            const chaos::str::UTF8String& path,
            const chaos::str::UTF8String& id );

    virtual void close_test();

    virtual void report_crash( const chaos::str::UTF8String& info );

    virtual void report_check_pass(
            const chaos::str::UTF8String& type,
            const chaos::str::UTF8String& file,
                  chaos::int32            line );

    virtual void report_check_fail(
            const chaos::str::UTF8String& type,
            const chaos::str::UTF8String& file,
                  chaos::int32            line,
            const chaos::str::UTF8String& message );

    virtual void write_message( const chaos::str::UTF8String& message );

    virtual void finialise_test_report(
            chaos::uint64 checks_passed,
            chaos::uint64 checks_failed );
};

} // namespace log_formatter
} // namespace test
} // namespace chaos

#endif

#endif
