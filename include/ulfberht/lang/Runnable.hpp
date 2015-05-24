#ifndef INCLUDE_ULFBERHT_LANG_RUNNABLE_
#define INCLUDE_ULFBERHT_LANG_RUNNABLE_

/*
 * Author: jrahm
 * created: 2015/05/22
 * Runnable.hpp: <description>
 */

namespace lang {

/** A class that runs and optionally returns
 * a return code in the form of an int.
 */
class Runnable /* ** interface ** */ {
public:
    /**
     * @brief Runs the object
     * @return A status code for the run
     */
    virtual int run() = 0;

    virtual inline ~Runnable() {};
};

}

#endif /* INCLUDE_ULFBERHT_LANG_RUNNABLE_ */
