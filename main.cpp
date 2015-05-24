#include <ulfberht/logger/LogManager.hpp>

using namespace logger;

int main(int argc, char** argv) {
	Log& log = GET_LOG("Test/Fn/Main");
	LogManager::instance().logEverything();

	log.printfln(INFO, "Hello, World!");
	return 0;
}
