#ifndef INCLUDE_ULFBERHT_LANG_MANAGEDRUNNABLE_
#define INCLUDE_ULFBERHT_LANG_MANAGEDRUNNABLE_

/*
 * Author: jrahm
 * created: 2015/05/22
 * ManagedRunnable.hpp: <description>
 */

#include <ulfberht/lang/Runnable.hpp>

namespace lang {

/**
 * @brief A runnable that can be told to stop.
 */
class ManagedRunnable: public Runnable {
public:
    /**
     * Tells the runnable to stop
     * @return a status code
     */
    int stop();

    virtual inline ~ManagedRunnable() {};
};

}

#endif /* INCLUDE_ULFBERHT_LANG_MANAGEDRUNNABLE_ */
