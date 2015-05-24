#include <ulfberht/os/Thread.hpp>
#include <map>

using namespace std;
using namespace lang;

namespace os {

void* os_Thread__thread_start(void* runner) {
    Runnable* l_runner = (Runnable*) runner;
    l_runner->run();

    pthread_exit(NULL);
}

map<pthread_t, Thread*> s_thread_db;

Thread* Thread::currentThread() {
    pthread_t key = pthread_self();
    map<pthread_t,Thread*>::iterator itr;

    itr = s_thread_db.find(key);
    if(itr == s_thread_db.end()) {
        return NULL;
    }

    return itr->second;
}

Thread::Thread(lang::Runnable& runner):
    m_runner(runner) {}

}
