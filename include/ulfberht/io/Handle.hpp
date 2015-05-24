#ifndef INCLUDE_ULFBERHT_IO_HANDLE_
#define INCLUDE_ULFBERHT_IO_HANDLE_

/*
 * Author: jrahm
 * created: 2015/05/24
 * Handle.hpp: <description>
 */

#include <ulfberht/io/BaseIO.hpp>
#include <ulfberht/io/HasRawHandle.hpp>

#include <unistd.h>

namespace io {

class Handle: public BaseIO, public HasRawHandleTempl {
public:
    inline Handle(raw_handle_t handle)
        { m_handle = handle; }

    inline size_t write(const byte* bytes, size_t len) OVERRIDE {
        return ::write(m_handle, bytes, len);
    }

    inline ssize_t read(byte* bytes, size_t len) OVERRIDE {
        return ::read(m_handle, bytes, len);
    }

    inline int read() {
        byte b;
        if(::read(m_handle, &b, 1) > 0) return b;
        return -1;
    }

    inline virtual bool write(byte b) {
        return ::write(m_handle, &b, 1) > 0;
    }

    virtual inline ~Handle() {
        ::close(m_handle);
    }

private:
    raw_handle_t m_handle;
};

}

#endif /* INCLUDE_ULFBERHT_IO_HANDLE_ */
