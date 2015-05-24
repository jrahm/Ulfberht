#ifndef INCLUDE_ULFBERHT_OS_THREAD_
#define INCLUDE_ULFBERHT_OS_THREAD_

/*
 * Author: jrahm
 * created: 2015/05/22
 * Thread.hpp: <description>
 */

#include <ulfberht/lang/Runnable.hpp>

#include <pthread.h>

namespace os {

typedef int thread_id_t;

class Thread {
public:
    /**
     * @brief Creates a new thread that runs the runnable once it starts
     * @param runner The runnable to run at the start
     */
    Thread(lang::Runnable& runner);

    static Thread* currentThread();
    
    /**
     * @brief return the id of the thread
     * @return the id of the thread
     */
    virtual thread_id_t getId() const;
    
    /**
     * @brief Start the current thread
     */
    virtual void start();

    /**
     * @brief Waits for this thread to complete
     */
    virtual void join();

    /**
     * @return the runnable for this thread
     */
    virtual const lang::Runnable& getRunnable() const;
    virtual lang::Runnable& getRunnable();


    pthread_t raw();

private:
    pthread_t m_thread;
    lang::Runnable& m_runner;
};

}

#endif /* INCLUDE_ULFBERHT_OS_THREAD_ */
