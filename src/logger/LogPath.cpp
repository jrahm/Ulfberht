#include <ulfberht/logger/LogPath.hpp>

using namespace std;

namespace logger {

LogPath::LogPath(const char* path) {
    parse_path(path);
}

const vector<string>& LogPath::getLogPath() const {
    return m_log_path;
}

std::string& LogPath::toString(std::string& into) const {
    into.clear();

    for (vector<string>::const_iterator itr = m_log_path.begin();
            itr != m_log_path.end() ; ++ itr ) {
            into += "/";
            into += *itr;
        }

    return into;
}

void LogPath::parse_path(const char* path) {
    std::string current;
    while(*path == '/') ++ path;

    for( ; *path != 0 ; ++ path ) {
        if( *path == '/' ) {
            while(*(path + 1) == '/') ++ path;
            m_log_path.push_back(current);
            current.clear();
        } else {
            current += *path;
        }
    }
    m_log_path.push_back(current);
}

}
