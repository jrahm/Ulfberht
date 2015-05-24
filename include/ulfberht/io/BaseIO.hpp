#ifndef INCLUDE_ULFBERHT_IO_BASEIO_
#define INCLUDE_ULFBERHT_IO_BASEIO_

/*
 * Author: jrahm
 * created: 2015/05/22
 * BaseIO.hpp: <description>
 */

#include <ulfberht/io/BaseInput.hpp>
#include <ulfberht/io/BaseOutput.hpp>

namespace io {

/**
 * @brief Combination of the BaseInput and BaseOutput classes.
 */
class BaseIO: public BaseInput, public BaseOutput {
public:
    virtual inline ~BaseIO() {};
};

};

#endif /* INCLUDE_ULFBERHT_IO_BASEIO_ */
