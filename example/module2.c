#include "logger/logger.h"

LOGGER_REGISTER_MODULE("module2", LOG_LEVEL_ALL);

void module2_foo(void) {
    LOG_ERR("Some error message from module2");
}
