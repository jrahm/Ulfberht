#ifndef INCLUDE_ULFBERHT_IO_STRINGINPUTSTREAM_
#define INCLUDE_ULFBERHT_IO_STRINGINPUTSTREAM_

#include <ulfberht/io/BaseInput.hpp>
#include <string>

namespace io {

class StringInputStream: public BaseInput {
public:
    StringInputStream(const std::string& input):
        m_Input(input), head(0) {}

    virtual inline int read() {
        if(head == m_Input.length()) return -1;
        return m_Input[head++];
    }

private:
    std::string m_Input;
    size_t head;
};

}

#endif /* INCLUDE_ULFBERHT_IO_STRINGINPUTSTREAM_ */
