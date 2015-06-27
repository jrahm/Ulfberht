#ifndef INCLUDE_ULFBERHT_LANG_EXCEPTION_
#define INCLUDE_ULFBERHT_LANG_EXCEPTION_

#include <Prelude.hpp>

#include <string>
#include <vector>


namespace lang {

class Exception {
public:
	static const u32_t MAX_BACKTRACE = 100;

    /**
     * @brief Construct a new exception
     * @param message the message to send with the exception
     */
    Exception(const char* message);

    /**
     * @return The message for this exception
     */
    virtual const std::string& getMessage() const;

private:
    std::string m_message;
	std::vector<void*> m_backtrace;
};

}

#endif /* INCLUDE_ULFBERHT_LANG_EXCEPTION_ */
