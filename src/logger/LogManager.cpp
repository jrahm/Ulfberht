#include <ulfberht/logger/LogManager.hpp>
#include <ulfberht/collections/PathTree.hpp>
#include <ulfberht/lang/System.hpp>

#include <map>

using namespace std;

namespace logger {

typedef collections::PathTree<Log*> LogTree;

template<bool enable>
void basic_set_enable(const vector<string>& _path, Log* log) {
    (void)_path;
    if(log)
        log->setEnabled(enable);
}

template<bool enable>
void set_enable_log(const vector<string>& _path, Log* log) {
    (void)_path;

    if(log) {
        if(enable) log->setMinimumLogLevel(ZERO);
        log->setEnabled(enable);
    }
}

class LogManagerImpl: public LogManager {
public:
    LogManagerImpl():
        m_default_log_output(lang::System::out, true) {}

    void setLogOutput(LogOutput& output) {
        m_default_log_output = output;
    }

    Log& getLog(const LogPath& path) {
        const vector<string>& log_path = path.getLogPath();
        LogTree& tmp = m_log_tree.get(log_path);

        std::string str;

        if(!tmp.HasElement()) {
            Log* new_log = new Log(path.toString(str), m_default_log_output);
            new_log->setEnabled(default_enabled);
            tmp.setElement(new_log);
        }

        return * tmp.getElement();
    }

    void logEverything() {
        default_enabled = true;
        m_log_tree.walk(set_enable_log<true>);
    }

    void logNothing() {
        default_enabled = false;
        m_log_tree.walk(set_enable_log<false>);
    }

    void setEnableByDefault(bool enable)
        { default_enabled = enable; }

    void setLogEnabled(const LogPath& path, bool yes) {
        LogTree* sub_tree = m_log_tree.navigate(path.getLogPath());
        if(sub_tree) {
            if(yes) {
                sub_tree->walk(basic_set_enable<true>);
            } else {
                sub_tree->walk(basic_set_enable<false>);
            }
        }
    }


private:

    bool default_enabled;
    LogOutput m_default_log_output;
    LogTree m_log_tree;
};

LogManagerImpl* g_log_manager;

LogManager& LogManager::instance() {
    if(!g_log_manager) g_log_manager = new LogManagerImpl();
    return *g_log_manager;
}

};
