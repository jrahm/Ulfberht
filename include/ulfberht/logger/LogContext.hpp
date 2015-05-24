#ifndef INCLUDE_ULFBERHT_LOGGER_LOGCONTEXT_
#define INCLUDE_ULFBERHT_LOGGER_LOGCONTEXT_

/*
 * Author: jrahm
 * created: 2015/05/23
 * LogContext.hpp: <description>
 */

#include <vector>
#include <string>

namespace logger {

class LogPath {
public:
    LogPath (const char* path);

    const std::vector<std::string>& getLogPath() const;

private:
    void parse_path(const char* path);

    std::vector<std::string> m_log_path;
};

}

#endif /* INCLUDE_ULFBERHT_LOGGER_LOGCONTEXT_ */
