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

class Handle: public BaseIO, public HasRawHandle {
public:
    inline Handle(raw_handle_t handle)
        { m_handle = handle; }

    inline size_t write(const byte* bytes, size_t len) OVERRIDE {
        return ::write(m_handle, bytes, len);
    }

    inline ssize_t read(byte* bytes, size_t len) OVERRIDE {
        return ::read(m_handle, bytes, len);
    }

    virtual inline ~Handle() {
        ::close(m_handle);
    }

private:
    raw_handle_t m_handle;
};

}

#endif /* INCLUDE_ULFBERHT_IO_HANDLE_ */
