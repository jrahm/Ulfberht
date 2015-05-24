#include <ulfberht/logger/Log.hpp>

namespace logger {

Log::Log(const std::string& prefix, LogOutput& lo, const LogLevel& min):
    m_prefix_str(prefix), m_log_output(lo), m_min_log_level(min) {}

void Log::printfln(const LogLevel& level, const char* fmt, ...) {
    if(level < m_min_log_level) return;

    va_list va;
    va_start(va,fmt);

    _vprintfln(level, fmt, va);
}

void Log::vprintfln(const LogLevel& level, const char* fmt, va_list l) {
    if(level < m_min_log_level) return;
    _vprintfln(level, fmt, l);
}

void Log::_vprintfln(const LogLevel& level, const char* fmt, va_list va) {
    if(m_log_output.isColorEnabled())
        m_log_output.printfln(level.getEscapeSequence());

    m_log_output.printfln(m_prefix_str.c_str());
    m_log_output.vprintf(fmt, va);
    m_log_output.printf("\n");
}

}
