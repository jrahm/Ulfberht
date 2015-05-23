#ifndef INCLUDE_IO_BASEINPUT_
#define INCLUDE_IO_BASEINPUT_

/*
 * Author: jrahm
 * created: 2015/05/22
 * BaseInput.hpp: <description>
 */

#include <Prelude.hpp>

namespace io {

/**
 * @brief Abstract class that is roughly equivalent to an InputStream
 *
 * The required function to implement is the `read` function.
 */
ABSTRACT class BaseInput {
public:

/**
 * @brief Abstract function. Read some bytes from this base input.
 * 
 * @param into the byte buffer to read from
 * @param len the length of the byte array to read into
 *
 * This function reads bytes into `into`, but does
 * not guarantee that all `len` bytes will be filled. For
 * that, the number of bytes read is returned.
 *
 * In the case the stream has reached EOF, -1 is returned.
 */
virtual inline ssize_t read(byte* into, size_t len) {

    /* Default implementation: use read() */
    for(size_t i = 0; i < len; ++ i) {
        int t = read();
        if(t < 0) return i;
        into[i] = t;
    }
    return len;
}

/**
 * @brief Read one byte from the input
 * @return byte read, or -1 if no more was read.
 *
 * Reads one byte from the stream. In the event there is an EOF or other
 * error, -1 is returned to indicate no data.
 */
virtual int read() = 0;
    
};

}

#endif /* INCLUDE_IO_BASEINPUT_ */
