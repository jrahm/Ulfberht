#ifndef INCLUDE_ULFBERHT_IO_HASRAWHANDLE_
#define INCLUDE_ULFBERHT_IO_HASRAWHANDLE_

/*
 * Author: jrahm
 * created: 2015/05/22
 * HasRawHandle.hpp: <description>
 */

#include <Prelude.hpp>

namespace io {

/**
 * @brief Interface that describes a class containing a raw file handle
 */
class HasRawHandle /* ** interface ** */ {
public:
    /**
     * @brief Returns the raw handle in this object
     * @return The raw handle in this object
     */
    virtual raw_handle_t getRawHandle() = 0;

    virtual inline ~HasRawHandle() {};
};

class HasRawHandleTempl: public HasRawHandle {
public:
    virtual inline raw_handle_t getRawHandle() { return m_handle; }

protected:
    raw_handle_t m_handle;
};

}

#endif /* INCLUDE_ULFBERHT_IO_HASRAWHANDLE_ */
