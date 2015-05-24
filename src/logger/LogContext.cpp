#include <ulfberht/logger/LogContext.hpp>

namespace logger {

LogPath::LogPath(const char* path) {
    parse_path(path);
}

void LogPath::parse_path(const char* path) {
    std::string current;
    for( ; *path != 0 ; ++ path ) {
        if( *path == '/' ) {
            m_log_path.push_back(current);
            current.clear();
        } else {
            current += *path;
        }
    }
    m_log_path.push_back(current);
}

}
