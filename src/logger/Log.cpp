#include <ulfberht/logger/Log.hpp>

namespace logger {

Log::Log(const std::string& prefix, LogOutput& lo, const LogLevel& min):
    m_prefix_str(prefix), m_log_output(lo), m_min_log_level(&min), m_enabled(false) {}

void Log::printfln(const LogLevel& level, const char* fmt, ...) {
    if(level < *m_min_log_level || !m_enabled) return;

    va_list va;
    va_start(va,fmt);

    _vprintf(level, fmt, va);
    m_log_output.printf("\n");
}

void Log::vprintf(const LogLevel& level, const char* fmt, va_list l) {
    if(level < *m_min_log_level || !m_enabled) return;
    _vprintf(level, fmt, l);
}

void Log::vprintfln(const LogLevel& level, const char* fmt, va_list l) {
    if(level < *m_min_log_level || !m_enabled) return;
    _vprintf(level, fmt, l);
    m_log_output.printf("\n");
}

void Log::printf(const LogLevel& level, const char* fmt, ...) {
    if(level < *m_min_log_level || !m_enabled) return;
    va_list va;
    va_start(va, fmt);
    _vprintf(level, fmt, va);
}

void Log::_vprintf(const LogLevel& level, const char* fmt, va_list va) {
    if(m_log_output.isColorEnabled())
        m_log_output.printf(level.getEscapeSequence());

    static byte* buffer = (byte*)"                 ";

    m_log_output.printf("[%s][%s]", level.getName().c_str(), m_prefix_str.c_str());
    m_log_output.getBaseOutput().write(buffer, 10 - level.getName().size());
    m_log_output.vprintf(fmt, va);
}

}
