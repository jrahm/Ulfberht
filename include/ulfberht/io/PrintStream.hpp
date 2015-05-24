#ifndef INCLUDE_ULFBERHT_IO_PRINTSTREAM_
#define INCLUDE_ULFBERHT_IO_PRINTSTREAM_

/*
 * Author: jrahm
 * created: 2015/05/24
 * PrintStream.hpp: <description>
 */

#include <ulfberht/io/BaseOutput.hpp>
#include <cstdarg>

namespace io {

class PrintStream: public BaseOutput {
public:
    PrintStream(BaseOutput& out);

    virtual void printf(const char* fmt, ...);
    virtual void vprintf(const char* fmt, va_list l);

    inline virtual void printfln(const char* fmt, ...) {
        va_list va;
        va_start(va, fmt);
        this->vprintf(fmt, va);
        this->printf("\n");
    }

    inline virtual bool write(byte val) 
        { return m_output->write(val); }

    inline BaseOutput& getBaseOutput()
        { return *m_output; };
    inline const BaseOutput& getBaseOutput() const
        { return *m_output; };

private:
    BaseOutput* m_output;
};

}

#endif /* INCLUDE_ULFBERHT_IO_PRINTSTREAM_ */
