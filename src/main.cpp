#include <ulfberht/logger/LogManager.hpp>

using namespace logger;

int main(int argc, char** argv) {
	Log& log = GET_LOG("Test/Fn/Main");
	log.printfln(TRACE, "Should Not Appear!");

	LogManager::instance().logEverything();

	log.printfln(VERBOSE, "This should appear!");
	log.printfln(INFO, "Hello, World!");

	LogManager::instance().setLogEnabled("Test/Fn", false);
	log.printfln(INFO, "Should not appear!");
	LogManager::instance().setLogEnabled("Test/Fn/Main", true);
	log.printfln(ERROR, "This should appear!");

	return 0;
}
