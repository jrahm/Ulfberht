#ifndef INCLUDE_ULFBERHT_LOGGER_LOG_
#define INCLUDE_ULFBERHT_LOGGER_LOG_

/*
 * Author: jrahm
 * created: 2015/05/23
 * Log.hpp: <description>
 */

#include <ulfberht/logger/LogLevel.hpp>
#include <ulfberht/logger/LogOutput.hpp>

#include <cstdarg>

#ifndef DEFAULT_LOG_LEVEL
#   define DEFAULT_LOG_LEVEL DEBUG
#endif

namespace logger {

class Log {
public:
    Log(const std::string& prefix, LogOutput& lo, const LogLevel& min=DEFAULT_LOG_LEVEL);

    void printfln(const LogLevel& level, const char* fmt, ...);
    void vprintfln(const LogLevel& level, const char* fmt, va_list lst);

    void setLogOutput(LogOutput& lo)
        { m_log_output = lo; }

    inline void setMinimumLogLevel(const LogLevel& ll)
        { m_min_log_level = ll; }

    inline const LogLevel& getMinimumLogLevel() const
        { return m_min_log_level; }

private:
    void _vprintfln(const LogLevel& level, const char* fmt, va_list lst);

    std::string m_prefix_str;
    LogOutput m_log_output;
    LogLevel m_min_log_level;
};

}

#endif /* INCLUDE_ULFBERHT_LOGGER_LOG_ */
