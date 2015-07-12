#ifndef INCLUDE_ULFBERHT_LANG_EXCEPTIONHANDLER_
#define INCLUDE_ULFBERHT_LANG_EXCEPTIONHANDLER_

/*
 * Author: jrahm
 * created: 2015/05/26
 * ExceptionHandler.hpp: <description>
 */

#include <ulfberht/lang/Exception.hpp>


namespace lang {

template <class ExcpT>
class ExceptionHandler {
public:
	virtual void onException(ExcpT& excp) = 0;
};

}

#endif /* INCLUDE_ULFBERHT_LANG_EXCEPTIONHANDLER_ */
