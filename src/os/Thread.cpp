#include <ulfberht/os/Thread.hpp>
#include <map>

#include <Prelude.hpp>
#include <ulfberht/logger/LogManager.hpp>
#include <ulfberht/lang/Exception.hpp>
#include <ulfberht/lang/System.hpp>

using namespace logger;
using namespace lang;

namespace os {


std::map<pthread_t, Thread*> s_thread_db;

Thread* Thread::getCurrentThread() {
    return s_thread_db[pthread_self()];
}

static void* run_thread( void* _thread ) {
    try {
    	Thread* thread = (Thread*) _thread;
    	thread->getRunnable().run();
    } catch(Exception& ex) {
        System::getGlobalUncaughtExceptionHandler().onException(ex);
    }

	pthread_exit(NULL);
}

Thread::Thread(Runnable& runner) : m_runner(runner) {
	m_thread = (pthread_t)0;
    joined = false;
}

int Thread::start() {
    int rc;
	rc = pthread_create(&m_thread, NULL, run_thread, this);
    s_thread_db[m_thread] = this;
    return rc;
}

int Thread::join() {
    if( ! joined ) {
        int ret;
    	ret = pthread_join(m_thread, NULL);
        joined = true;
        return ret;
    }
    return 0;
}

Thread::~Thread() {
    join();
    s_thread_db[m_thread]=NULL;
}

}
