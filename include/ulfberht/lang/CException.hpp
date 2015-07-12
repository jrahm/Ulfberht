#ifndef INCLUDE_ULFBERHT_LANG_CEXCEPTION_
#define INCLUDE_ULFBERHT_LANG_CEXCEPTION_

#include <ulfberht/lang/Exception.hpp>

#include <cstdio>
#include <cerrno>
#include <cstring>

namespace lang {

class CException : public Exception {
public:
    inline CException(const char* message, int rc) :
        Exception(message) {
        char buf[4096];

        snprintf(buf, sizeof(buf), "%s (%d): %s",
            message, rc, strerror(rc));

        m_message = buf;
    }

    inline CException( int rc ) {
        this->rc = rc;
        m_message = strerror(rc);
    }

    inline int getCode() {
        return rc;
    }
private:
    int rc;
};

}

#endif /* INCLUDE_ULFBERHT_LANG_CEXCEPTION_ */
