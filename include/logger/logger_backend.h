#pragma once

#include <stdint.h>

#include "logger_common.h"

typedef void loggerEmitLogCallbackFunction(const char *const log, uint16_t log_size);
                           
void logger_printParamsList(const struct loggerMessage *const message);
void logger_printMessage(const struct loggerMessage *const message);
void logger_printModulesLevels(void);
void logger_setModuleLogLevelByIndex(uint16_t module_index, uint8_t log_level);
void logger_setModuleLogLevelByName(char *module_name, uint8_t log_level);
