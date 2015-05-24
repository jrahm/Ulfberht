#include <ulfberht/io/PrintStream.hpp>
#include <cstdio>

namespace io {

PrintStream::PrintStream(BaseOutput& out):
    m_output(&out) {}

void PrintStream::printf(const char* fmt, ...) {
    va_list va;
    va_start(va, fmt);
    vprintf(fmt, va);
}

void PrintStream::vprintf(const char* fmt, va_list va) {
    char outbuf[4096];
    int sz;

    sz = vsnprintf(outbuf, sizeof(outbuf), fmt, va);
    if(sz >= (s32_t)sizeof(outbuf)) {
        char* next = new char[sz+1];
        vsnprintf(next, sz+1, fmt, va);
        m_output->write((byte*)next, sz);
        delete[] next;
    } else {
        m_output->write((byte*)outbuf, sz);
    }
}

}
