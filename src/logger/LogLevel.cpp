#include <ulfberht/logger/LogLevel.hpp>
#include <map>

using namespace std;

namespace logger {

map<string, LogLevel*> g_log_level_db;

LogLevel::LogLevel(u32_t level, const char* name, const char* esc):
    m_esc(esc), m_name(name), m_level(level) {
    g_log_level_db[name] = this;
}

LogLevel* LogLevel::getLogLevelByName(const char* name) {
    typename map<string, LogLevel*>::iterator itr;
    itr = g_log_level_db.find(name);
    if(itr == g_log_level_db.end()) return NULL;
    return itr->second;
}

}

using namespace logger;

LogLevel ZERO(0, "Zero", "\033[1;30m");
LogLevel VERBOSE(5, "Verbose", "\033[1;34m");
LogLevel TRACE(10, "Trace", "\033[1;34m");
LogLevel DEBUG(20, "Debug", "\033[1;35m");
LogLevel INFO(40, "Info", "\033[1;37m");
LogLevel WARN(80, "Warn", "\033[1;33m");
LogLevel ERROR(160, "Error", "\033[1;31m");
LogLevel FATAL(320, "Fatal", "\033[0;31m");
