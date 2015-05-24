#ifndef INCLUDE_ULFBERHT_LOGGER_LOGLEVEL_
#define INCLUDE_ULFBERHT_LOGGER_LOGLEVEL_

/*
 * Author: jrahm
 * created: 2015/05/23
 * LogLevel.hpp: <description>
 */

#include <string>
#include <Prelude.hpp>

namespace logger {

class LogLevel {
public:
    LogLevel(u32_t level, const char* name, const char* esc);

    inline const char* getEscapeSequence() const
        {return m_esc.c_str();}

    inline const char* getName() const
        {return m_name.c_str();}

    inline bool operator>(const LogLevel& oth) const
        { return m_level > oth.m_level; } 

    inline bool operator>=(const LogLevel& oth) const
        { return m_level >= oth.m_level; } 

    inline bool operator<(const LogLevel& oth) const
        { return m_level < oth.m_level; }

    inline bool operator<=(const LogLevel& oth) const
        { return m_level <= oth.m_level; }

    static LogLevel* getLogLevelByName(const char* name);

private:
    std::string m_esc;
    std::string m_name;
    u32_t m_level;
};

extern LogLevel ZERO; /* 0 */

extern LogLevel VERBOSE; /* 5 */
extern LogLevel TRACE;   /* 10 */
extern LogLevel DEBUG;   /* 20 */
extern LogLevel INFO;    /* 40 */
extern LogLevel WARN;    /* 80 */
extern LogLevel ERROR;   /* 160 */
extern LogLevel FATAL;   /* 320 */

}

#endif /* INCLUDE_ULFBERHT_LOGGER_LOGLEVEL_ */
