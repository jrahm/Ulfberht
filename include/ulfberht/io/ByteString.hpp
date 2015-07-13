#ifndef INCLUDE_ULFBERHT_IO_BYTESTRING_
#define INCLUDE_ULFBERHT_IO_BYTESTRING_

/**
 * A lazy bytestring which is used as a client
 * to an input stream.
 */

#include <Prelude.hpp>

#include <string>
#include <vector>

namespace io {

class BaseInput;

class ByteString {
public:
    static const size_t BLOCK_SIZE = 4096;

    ByteString(BaseInput& input);
    ~ByteString();

    char operator[](size_t index);
    std::string substring(size_t start, size_t len);

    int compare(const std::string& str, size_t start, size_t len);
    int compare(const std::string& str, size_t start);

    /* Attempts to get the length of the ByteString,
     * however, if the bytestring is not fully evaluated,
     * it will return -1 */
    ssize_t length();

private:
    /* Read a new block into the array of
     * blocks */
    bool p_ReadBlock();
    bool p_TryFill();
    
    struct block {
        u32_t m_Size;
        char m_Bytes[BLOCK_SIZE];
    };

    struct block* p_LastBlock();
    std::vector<struct block*> m_Blocks;
    BaseInput& m_Input;

    bool m_IsEof;
};

}

#endif /* INCLUDE_ULFBERHT_IO_BYTESTRING_ */
