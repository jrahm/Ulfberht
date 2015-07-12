#ifndef SRC_LANG_MAYBE_
#define SRC_LANG_MAYBE_

/*
 * Author: jrahm
 * created: 2015/06/08
 * Maybe.hpp: <description>
 */

#include <ulfberht/lang/Exception.hpp>

namespace lang {

class NullMaybeException: public Exception {
    NullMaybeException(char* msg): Exception(msg) {}
    NullMaybeException(): Exception("Attempt to draw from Nothing") {};
};

template<class T>
class Maybe {
public:
    static inline Maybe just(const T& t) {
        Maybe ret;
        ret.m_val = new T(t);
        return ret;
    }

    static inline Maybe nothing() {
        Maybe ret;
        ret.m_val = NULL;
        return ret;
    }

    Maybe(const Maybe& oth) {
        m_val = NULL;
        *this = oth;
    }

    inline ~Maybe() { delete m_val; }

    inline Maybe& operator=(const Maybe& oth) {
        delete this->m_val;
        this->m_val = new T(*oth.m_val);
        return *this;
    }

    T& get() {
        if(!m_val) throw NullMaybeException();
        return *m_val;
    }

    bool isNothing() {
        return !m_val;
    }

    bool isSomething() {
        return !isNothing();
    }
        
private:
    Maybe() {};
    T* m_val;
};

}

#endif /* SRC_LANG_MAYBE_ */
