#ifndef RUNNABLE_HPP_
#define RUNNABLE_HPP_

#include <Prelude.hpp>

namespace os {

/**
 * @brief a class that can simply run
 */
class Runnable {
public:
	inline virtual ~Runnable(){};
    /**
     * @brief run the runnable
     */
	virtual void run() = 0;
};

/**
 * @brief A templated class that allows the running of a function with one argument.
 * @param T the type of argument the function expects
 */
template <typename T>
class FunctionRunner : public Runnable {
public:
    /**
     * @brief Construct a FunctionRunner with a function and an argument
     * 
     * @param func The function to run
     * @param arg  The argument to that function
     */
	FunctionRunner(void(*func)(T&arg), const T& arg) {
		m_function = func;
		m_arg = arg;
	}

	void run() OVERRIDE {
		m_function( m_arg );
	}
private:
	T m_arg;
	void (*m_function)(T& arg);
};

template <typename T>
class MemberFunctionRunner: public Runnable {
public:
    MemberFunctionRunner(void(T::*fn)(), T& obj):
        m_fn(fn),
        m_obj(obj){}

    void run() OVERRIDE {
        (m_obj.*m_fn)();
    }
private:
    void (T::*m_fn)();
    T& m_obj;
};

/**
 * A runnable that may be signaled to be stopped.
 */
class ManagedRunnable: public Runnable {
public:
    virtual void stop() = 0 ;
};

}

#endif
