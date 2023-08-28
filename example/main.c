#include <stdio.h>
#include <stdint.h>

#include "module1.h"
#include "module2.h"

#include "logger/logger_backend.h"

int main(void) {

	logger_setModuleLogLevelByName("module1", 0);
	module1_foo();
	
	module2_foo();
	logger_printMessage(&__logger_buffer[0]);

	logger_printModulesLevels();
}
