#ifndef INCLUDE_ULFBERHT_LANG_EXCEPTION_
#define INCLUDE_ULFBERHT_LANG_EXCEPTION_

#include <Prelude.hpp>

#include <string>
#include <vector>

#include <ulfberht/io/BaseOutput.hpp>


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

    /**
     * Print a stack trace to an output stream
     */
    virtual void printStackTrace(io::BaseOutput& out) const;

protected:
    inline Exception(){};
    std::string m_message;

private:
	std::vector<void*> m_backtrace;
};

}

#endif /* INCLUDE_ULFBERHT_LANG_EXCEPTION_ */
