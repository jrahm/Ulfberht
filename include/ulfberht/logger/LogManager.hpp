#ifndef INCLUDE_ULFBERHT_LOGGER_LOGMANAGER_
#define INCLUDE_ULFBERHT_LOGGER_LOGMANAGER_

/*
 * Author: jrahm
 * created: 2015/05/23
 * LogManager.hpp: <description>
 */

#include <ulfberht/logger/Log.hpp>
#include <ulfberht/logger/LogContext.hpp>

namespace logger {

#define GET_LOG(context) \
    LogManager::instance().getLogContext(context)

class LogManager {
public:
    static LogManager& instance();

    virtual Log& getLogContext(const LogPath& ctx) = 0;
    inline virtual Log& getLogContext(const char* path) 
        { return getLogContext(LogPath(path)); }

    virtual void disableLogPath(const LogPath& path) = 0;
    inline virtual void disableLogPath(const char* path)
        { disableLogPath(LogPath(path)); }

    virtual void enableLogPath(const LogPath& path) = 0;
    inline virtual void enableLogPath(const char* path)
        { enableLogPath(path); }
    
    /**
     * @brief Enables all logs, current and future at all log levels.
     * 
     * The user may still be able to disable logs after this call, but
     * any log setup before this call is meaningless
     */
    virtual void logEverything() = 0;

    /**
     * @brief Similar to the above, but disables all logging
     */
    virtual void logNothing() = 0;
};

}

#endif /* INCLUDE_ULFBERHT_LOGGER_LOGMANAGER_ */
