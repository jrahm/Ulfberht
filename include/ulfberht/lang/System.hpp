#ifndef INCLUDE_ULFBERHT_LANG_SYSTEM_
#define INCLUDE_ULFBERHT_LANG_SYSTEM_

/*
 * Author: jrahm
 * created: 2015/05/24
 * System.hpp: <description>
 */

#include <ulfberht/io/BaseOutput.hpp>
#include <ulfberht/io/BaseInput.hpp>

#include <ulfberht/lang/ExceptionHandler.hpp>

namespace lang {

class System {
public:
    static io::BaseOutput& out;
    static io::BaseOutput& err;
    static io::BaseInput& in;

    static ExceptionHandler<Exception>& getGlobalUncaughtExceptionHandler();
    static void setGlobalUncaughtExceptionHandler(ExceptionHandler<Exception>& exh);

};

}

#endif /* INCLUDE_ULFBERHT_LANG_SYSTEM_ */
