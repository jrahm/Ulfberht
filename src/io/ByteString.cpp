#include <ulfberht/io/ByteString.hpp>
#include <ulfberht/io/BaseInput.hpp>

#include <ulfberht/lang/IndexOutOfBoundsException.hpp>

namespace io {

ByteString::ByteString(BaseInput& input):
  m_Input(input) {
    m_IsEof = false;
}

ByteString::block* ByteString::p_LastBlock() {
    if(m_Blocks.size() == 0) return NULL;
    return m_Blocks[m_Blocks.size()-1];
}

bool ByteString::p_TryFill() {
    block* last = p_LastBlock();
    if(!last || last->m_Size == BLOCK_SIZE) return false;

    ssize_t nRead = m_Input.read(((byte*)last->m_Bytes) + last->m_Size, BLOCK_SIZE - last->m_Size);
    if(nRead == -1) {
        m_IsEof = true;
        return false;
    }

    last->m_Size += nRead;
    return true;
}

bool ByteString::p_ReadBlock() {
    if(!p_TryFill()) {
        if(m_IsEof) return false;
        block* new_block = new block();
        new_block->m_Size = 0;
        m_Blocks.push_back(new_block);
        return p_TryFill();
    }

    return true;
}

char ByteString::operator[](size_t index) {
    size_t block_idx = index / BLOCK_SIZE;
    size_t ch_idx = index % BLOCK_SIZE;

    while(block_idx >= m_Blocks.size()) {
        if(!p_ReadBlock()) {
            throw lang::IndexOutOfBoundsException("Index out of bounds");
        }
    }

    block* blk = m_Blocks[block_idx];
    while(ch_idx >= blk->m_Size) {
        if(!p_TryFill()) {
            throw lang::IndexOutOfBoundsException("Index out of bounds");
        }
    }

    return blk->m_Bytes[ch_idx];
}

std::string ByteString::substring(size_t start, size_t len) {
    std::string ret;
    for(size_t i = 0; i < len; ++ i) {
        ret += (*this)[start + i];
    }
    return ret;
}

int ByteString::compare(const std::string& str, size_t start) {
    return compare(str, start, str.size());
}

int ByteString::compare(const std::string& str, size_t start, size_t len) {
    for(size_t i = 0; i < len; ++ i) {
        if((*this)[i + start] != str[i]) {
            return (*this)[i + start] < str[i] ? -1 : 1;
        }
    }

    return 0;
}

ssize_t ByteString::length() {
    if(!m_IsEof) return -1;

    block* last = p_LastBlock();
    if(last == NULL) return 0;
    return (m_Blocks.size() - 1) * BLOCK_SIZE + last->m_Size;
}

ByteString::~ByteString() {
    std::vector<block*>::iterator itr;
    for(itr = m_Blocks.begin() ; itr != m_Blocks.end() ; ++ itr)
        delete *itr;
}

}
