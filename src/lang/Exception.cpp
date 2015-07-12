#include <ulfberht/lang/Exception.hpp>

#include <execinfo.h>

using namespace std;

namespace lang {

Exception::Exception(const char* message): m_message(message) {
	size_t addrlen;

	void* addrlist[MAX_BACKTRACE];
	addrlen = backtrace(addrlist, MAX_BACKTRACE);

    char** symbols = backtrace_symbols(addrlist, addrlen);

	for(size_t i = 0; i < addrlen; ++ i) {
		m_backtrace.push_back(addrlist[i]);
	}

    delete[] symbols;
}

/**
 * Return the message in the exception
 */
const std::string& Exception::getMessage() const {
    return m_message;
}

void Exception::printStackTrace(io::BaseOutput& out) const {
  // Not implemented   
}

}
