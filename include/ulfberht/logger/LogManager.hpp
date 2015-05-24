#ifndef INCLUDE_ULFBERHT_LOGGER_LOGMANAGER_
#define INCLUDE_ULFBERHT_LOGGER_LOGMANAGER_

/*
 * Author: jrahm
 * created: 2015/05/23
 * LogManager.hpp: <description>
 */

#include <ulfberht/logger/Log.hpp>
#include <ulfberht/logger/LogPath.hpp>

namespace logger {

#define GET_LOG(path) \
    LogManager::instance().getLog(path)

class LogManager {
public:
    static LogManager& instance();

    virtual void setLogOutput(LogOutput& output) = 0;

    virtual Log& getLog(const LogPath& ctx) = 0;
    inline virtual Log& getLog(const char* path) 
        { return getLog(LogPath(path)); }

    virtual void setLogEnabled(const LogPath& path, bool enabled)
        { getLog(path).setEnabled(enabled); }
    inline virtual void setLogEnabled(const char* path, bool enabled)
        { setLogEnabled(LogPath(path), enabled); };

    virtual void setEnableByDefault(bool enable) = 0;
    
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

    virtual inline ~LogManager() {};
};

}

#endif /* INCLUDE_ULFBERHT_LOGGER_LOGMANAGER_ */
