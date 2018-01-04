#include <cassert>
#include <iostream>
#include <fstream>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/core/null_deleter.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/support/date_time.hpp>

namespace logging = boost::log;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;
namespace attrs = boost::log::attributes;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

// Here we define our application severity levels.
enum severity_level
{
    normal,
    notification,
    warning,
    error,
    critical
};


template< typename CharT, typename TraitsT >
inline std::basic_ostream< CharT, TraitsT >& operator<< (
    std::basic_ostream< CharT, TraitsT >& strm, severity_level lvl)
{
    static const char* const str[] =
    {
        "normal",
        "notification",
        "warning",
        "error",
        "critical"
    };
    if (static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)))
        strm << str[lvl];
    else
        strm << static_cast< int >(lvl);
    return strm;
}



int main()
{
    typedef sinks::synchronous_sink< sinks::text_ostream_backend > text_sink;
    boost::shared_ptr< text_sink > pSink(new text_sink);
    text_sink::locked_backend_ptr pBackend = pSink->locked_backend();
    
    boost::shared_ptr< std::ostream > pStream(&std::clog, boost::null_deleter());
    pBackend->add_stream(pStream);

    boost::shared_ptr< std::ofstream > pStream2(new std::ofstream("sample.log"));
    assert(pStream2->is_open());
    pBackend->add_stream(pStream2);
    
    pSink->set_formatter(expr::stream << expr::format_date_time<boost::posix_time::ptime>("TimeStamp", "%Y-%m-%d %H:%M:%S") <<
                                 " " <<
                                 "[" <<
                                 expr::attr<severity_level>("Severity") << 
                                 "]" <<
                                 " " <<
                                 expr::message);

    // Ok, we're ready to add the sink to the logging library
    logging::core::get()->add_sink(pSink);
    
    attrs::local_clock TimeStamp;
    logging::core::get()->add_global_attribute("TimeStamp", TimeStamp);
    
    src::logger lg;
    BOOST_LOG(lg) << "Hello world!";
    BOOST_LOG(lg) << "Echo : " << "Hello world!";
    BOOST_LOG(lg) << "Some log line with a counter";
    BOOST_LOG(lg) << "Another log line with the counter";
    BOOST_LOG(lg) << "Log Ended";

    src::severity_logger<severity_level> slg;
    BOOST_LOG_SEV(slg, normal) << "A normal severity message";
    BOOST_LOG_SEV(slg, warning) << "A warning severity message";
    BOOST_LOG_SEV(slg, error) << "An error severity message";
}


