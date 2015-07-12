#ifndef INCLUDE_ULFBERHT_IO_UNABLETOOPENFILEEXCEPTION_
#define INCLUDE_ULFBERHT_IO_UNABLETOOPENFILEEXCEPTION_

/*
 * Author: jrahm
 * created: 2015/06/08
 * UnableToOpenFileException.hpp: <description>
 */


#include <ulfberht/lang/Exception.hpp>

namespace io {

class UnableToOpenFileException: public lang::Exception {
public:
    UnableToOpenFileException(const char* msg): lang::Exception(msg){}
};

}

#endif /* INCLUDE_ULFBERHT_IO_UNABLETOOPENFILEEXCEPTION_ */
