#ifndef ULFBERHT_PARSER_PARSER_
#define ULFBERHT_PARSER_PARSER_

/**
 * Combinator-style parser for C++.
 */

#include <string>
#include <ulfberht/io/ByteString.hpp>

template <class T>

class Parser {
public:
    /**
     * Construct and return a parser in the failed state.
     */
    inline Parser(): m_MaybeValue(), m_Ptr(0) {}

    /**
     * Construct a new parser from the input stream
     * given.
     */
    inline Parser(io::BaseInput& bs, const T& initial):
        m_MaybeValue(new T(initial)),
        m_ByteString(new io::ByteString(bs)),
        m_Ptr(0) {}

    /**
     * Attempts to read a string from the parser. Fails if
     * there the string does not match the input.
     */
    Parser<std::string> string(const std::string& a_string) {
        /* Return failed if in failed state */
        if(isInFailed()) return Parser<std::string>();

        if(m_ByteString->compare(a_string, m_Ptr, a_string.size()) == 0) {
            return Parser<std::string>(m_Ptr + a_string.size(), m_ByteString, a_string);
        } else {
            return Parser();
        }
    }

    /**
     * Take from the parser while the condition function
     * holds true or until eof is returned.
     *
     * @param cond the condition to read on
     */
    Parser<std::string> takeWhile(bool (*cond)(char)) {
        /* return failed if is in failed state */
        if(isInFailed()) return Parser<std::string>();

        size_t nptr = m_Ptr;
        while((m_ByteString->length() == -1 || nptr < m_ByteString->length())
            && cond((*m_ByteString)[nptr])) {
            nptr ++;
        }
        
        return Parser<std::string>(nptr, m_ByteString, m_ByteString->substring(m_Ptr, nptr - m_Ptr));
    }

    /**
     * Return this parser, unless this parser is null
     * then return the other parser.
     */
    Parser& operator||(const Parser& oth) {
        if(this->isInFailed()) return oth;
        return *this;
    }

    /**
     * Returns whether this parser is in a failed state.
     * @return true if this parser is in a failed state
     */
    bool isInFailed() {
        return m_MaybeValue.get() == NULL;
    }

    T* operator->() { return m_MaybeValue.get(); }

    inline Parser(size_t new_ptr, uptr<io::ByteString> bs, const T& value):
    m_MaybeValue(new T(value)),
    m_ByteString(bs),
    m_Ptr(new_ptr)
    {}

    uptr<T> m_MaybeValue;
    uptr<io::ByteString> m_ByteString;

    size_t m_Ptr;
};

#endif /* ULFBERHT_PARSER_PARSER_ */
