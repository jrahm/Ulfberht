#ifndef INCLUDE_ULFBERHT_LOGGER_LOGOUTPUT_
#define INCLUDE_ULFBERHT_LOGGER_LOGOUTPUT_

/*
 * Author: jrahm
 * created: 2015/05/24
 * LogOutput.hpp: <description>
 */

#include <ulfberht/io/BaseOutput.hpp>
#include <ulfberht/io/PrintStream.hpp>

namespace logger {

class LogOutput: public io::PrintStream {
public:
    inline LogOutput(io::BaseOutput& output, bool colors=true)
        : io::PrintStream(output), m_colors_enabled(colors) {}

    inline bool isColorEnabled() const
        { return m_colors_enabled; }

private:
    bool m_colors_enabled;
};

};

#endif /* INCLUDE_ULFBERHT_LOGGER_LOGOUTPUT_ */
