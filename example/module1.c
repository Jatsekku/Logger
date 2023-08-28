#include "logger/logger.h"
LOGGER_REGISTER_MODULE("module1", LOG_LEVEL_ALL);

void module1_foo(void) {
    LOG_DBG("Some debug message from module1");
}
