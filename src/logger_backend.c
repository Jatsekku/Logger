#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

#include "logger/logger_common.h"

/* Modules Log Levels Section */
extern uint8_t __start_logger_levels;
extern uint8_t __stop_logger_levels;

struct loggerModulesLevels {
	uint8_t *start;
	uint8_t *stop;
};

const struct loggerModulesLevels logger_modules_levels = {
	.start = &__start_logger_levels,
	.stop = &__stop_logger_levels,
};

/* Modules Names Section */
extern const char *const __start_logger_names;
extern const char *const __stop_logger_names;

struct loggerModulesNames {
	const char **start;
	const char **stop;
};

const struct loggerModulesNames logger_modules_names = {
	.start = &__start_logger_names,
	.stop = &__stop_logger_names,
};

uint8_t __logger_buffer[100];

void logger_printParamsList(const struct loggerMessage *const message) {
	const char *const format_string = message->format_string;
	const uint16_t params_size = message->params_size;
	const void *param_list = message->params_list;
	uint16_t param_list_offset = 0;

	int i = 0;
	char current_char;
	bool inside_token = false;
	char output[255];

	while ('\0' != (current_char = format_string[i])) {
		if ('%' == current_char) {
			inside_token = true;
		}

		if (inside_token) {
			switch (current_char) {
				case 'f':
					const double *const f = (param_list + param_list_offset);
					printf("float: %f", *f);
					param_list_offset += sizeof(double);
					inside_token = false;
				break;
				case 'd':
					const int *const i = (param_list + param_list_offset);
					printf("int: %i", *i);
					param_list_offset += sizeof(int);
					inside_token = false;
				break;
			}
		} else {
			printf("%c", current_char);
		}
		i++;
	}
}

void logger_printMessage(const struct loggerMessage *const message) {

	printf("log_level: %d\n"
		   "module_name: %s\n"
		   "line: %d\n"
		   "format string: %s\n"
		   "params_size %d\n",
		   message->log_level,
		   message->module_name,
		   message->source_code_line,
		   message->format_string,
		   message->params_size);
	logger_printParamsList(message);
}

void logger_printModulesLevels(void) {
	const uint16_t modules_amount = logger_modules_levels.stop - logger_modules_levels.start;
	printf("\nModules amount: %d\n", modules_amount);
	for(int i = 0; i < modules_amount; i++) {
		printf("Module: %d, level: %d, names: %s\n", i, logger_modules_levels.start[i], logger_modules_names.start[i]);
	}
}

void logger_setModuleLogLevelByIndex(uint16_t module_index, uint8_t log_level) {
	logger_modules_levels.start[module_index] = log_level;
}

static int16_t findModuleIndex(char *token) {
	const uint16_t token_length = strlen(token);
	const uint16_t modules_amount = logger_modules_levels.stop - logger_modules_levels.start;

	for (int i = 0; i < modules_amount; i++) {
		char *current_module_name = logger_modules_names.start[i];
		uint16_t matched_chars = 0;

		for(int j = 0; j < token_length; j++) {
			if (token[j] != current_module_name[j]) {
				break;
			}

			if(++matched_chars == token_length) {
				return i;
			}
		}
	}

	return -1; 
}

void logger_setModuleLogLevelByName(char *module_name, uint8_t log_level) {
	const int16_t module_idx = findModuleIndex(module_name);
	if (module_idx < 0) {
		return;
	}

	logger_setModuleLogLevelByIndex(module_idx, log_level);
}
