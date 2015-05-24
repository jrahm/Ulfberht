#ifndef INCLUDE_ULFBERHT_LANG_SYSTEM_
#define INCLUDE_ULFBERHT_LANG_SYSTEM_

/*
 * Author: jrahm
 * created: 2015/05/24
 * System.hpp: <description>
 */

#include <ulfberht/io/BaseOutput.hpp>
#include <ulfberht/io/BaseInput.hpp>

namespace lang {

class System {
public:
    static io::BaseOutput& out;
    static io::BaseOutput& err;
    static io::BaseInput& in;
};

}

#endif /* INCLUDE_ULFBERHT_LANG_SYSTEM_ */
