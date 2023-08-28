#pragma once
#include <stdint.h>

#define LOGGER_MODULES_LEVELS_SECTION __attribute__((section("logger_levels")))
#define LOGGER_MODULES_NAMES_SECTION __attribute__((section("logger_names")))

struct loggerMessage {
	uint8_t log_level;
	const char *module_name;
	uint16_t source_code_line;
	const char *format_string;
	uint16_t params_size;
	uint8_t params_list[];
};

/* Replace with circle buffer later */
extern uint8_t __logger_buffer[100];
