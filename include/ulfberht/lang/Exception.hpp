#ifndef INCLUDE_ULFBERHT_LANG_EXCEPTION_
#define INCLUDE_ULFBERHT_LANG_EXCEPTION_

/*
 * Author: jrahm
 * created: 2015/05/23
 * Exception.hpp: <description>
 */

#include <string>

namespace lang {

class Exception {
public:
    Exception(const char* message);

    /**
     * @return The message for this exception
     */
    virtual const char* getMessage() const;

private:
    std::string message;
};

}

#endif /* INCLUDE_ULFBERHT_LANG_EXCEPTION_ */
