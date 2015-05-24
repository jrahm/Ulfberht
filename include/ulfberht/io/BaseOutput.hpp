#ifndef INCLUDE_IO_BASEOUTPUT_
#define INCLUDE_IO_BASEOUTPUT_

/*
 * Author: jrahm
 * created: 2015/05/22
 * BaseOutput.hpp: <description>
 */

#include <Prelude.hpp>

namespace io {

/**
 * @brief Abstract class that is roughly equivalent to an OutputStream
 */
ABSTRACT class BaseOutput {
public:

/**
 * @brief Write a byte array to this output
 * @param out The byte array to write
 * @param len The length of the byte array
 * @return the number of bytes written.
 *
 * This function will attempt to write `len` bytes to an output
 * stream. This function is not guaranteed to write
 * all the bytes to the output stream.
 */
virtual inline size_t write(const byte* out, size_t len) {
    for(size_t i = 0; i < len; ++ i) {
        if(!write(out[i])) return i;
    }
    return len;
}

/**
 * @brief writes a single value to the output
 * @param val the value to write
 * @return A code, true if the byte was sucessfully written,
 *          false if some expected error occured
 */
virtual bool write(byte val) = 0;

virtual inline ~BaseOutput() {};

};

}

#endif /* INCLUDE_IO_BASEOUTPUT_ */
