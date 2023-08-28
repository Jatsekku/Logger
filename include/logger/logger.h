#pragma once

#include <stdint.h>
#include <string.h>

#include "logger_common.h"

#define __LOGGER_FE_0(WHAT)
#define __LOGGER_FE_1(WHAT, X)       WHAT(1, X)
#define __LOGGER_FE_2(WHAT, X, ...)  WHAT(2, X)  __LOGGER_FE_1(WHAT, __VA_ARGS__)
#define __LOGGER_FE_3(WHAT, X, ...)  WHAT(3, X)  __LOGGER_FE_2(WHAT, __VA_ARGS__)
#define __LOGGER_FE_4(WHAT, X, ...)  WHAT(4, X)  __LOGGER_FE_3(WHAT, __VA_ARGS__)
#define __LOGGER_FE_5(WHAT, X, ...)  WHAT(5, X)  __LOGGER_FE_4(WHAT, __VA_ARGS__)
#define __LOGGER_FE_6(WHAT, X, ...)  WHAT(6, X)  __LOGGER_FE_5(WHAT, __VA_ARGS__)
#define __LOGGER_FE_7(WHAT, X, ...)  WHAT(7, X)  __LOGGER_FE_6(WHAT, __VA_ARGS__)
#define __LOGGER_FE_8(WHAT, X, ...)  WHAT(8, X)  __LOGGER_FE_7(WHAT, __VA_ARGS__)
#define __LOGGER_FE_9(WHAT, X, ...)  WHAT(9, X)  __LOGGER_FE_8(WHAT, __VA_ARGS__)
#define __LOGGER_FE_10(WHAT, X, ...) WHAT(10, X) __LOGGER_FE_9(WHAT, __VA_ARGS__)
#define __LOGGER_FE_11(WHAT, X, ...) WHAT(11, X) __LOGGER_FE_10(WHAT, __VA_ARGS__)
#define __LOGGER_FE_12(WHAT, X, ...) WHAT(12, X) __LOGGER_FE_11(WHAT, __VA_ARGS__)
#define __LOGGER_FE_13(WHAT, X, ...) WHAT(13, X) __LOGGER_FE_12(WHAT, __VA_ARGS__)
#define __LOGGER_FE_14(WHAT, X, ...) WHAT(14, X) __LOGGER_FE_13(WHAT, __VA_ARGS__)
#define __LOGGER_FE_15(WHAT, X, ...) WHAT(15, X) __LOGGER_FE_14(WHAT, __VA_ARGS__)
#define __LOGGER_FE_16(WHAT, X, ...) WHAT(16, X) __LOGGER_FE_15(WHAT, __VA_ARGS__)
#define __LOGGER_FE_17(WHAT, X, ...) WHAT(17, X) __LOGGER_FE_16(WHAT, __VA_ARGS__)
#define __LOGGER_FE_18(WHAT, X, ...) WHAT(18, X) __LOGGER_FE_17(WHAT, __VA_ARGS__)
#define __LOGGER_FE_19(WHAT, X, ...) WHAT(19, X) __LOGGER_FE_18(WHAT, __VA_ARGS__)
#define __LOGGER_FE_20(WHAT, X, ...) WHAT(20, X) __LOGGER_FE_19(WHAT, __VA_ARGS__)
#define __LOGGER_FE_21(WHAT, X, ...) WHAT(21, X) __LOGGER_FE_20(WHAT, __VA_ARGS__)
#define __LOGGER_FE_22(WHAT, X, ...) WHAT(22, X) __LOGGER_FE_21(WHAT, __VA_ARGS__)
#define __LOGGER_FE_23(WHAT, X, ...) WHAT(23, X) __LOGGER_FE_22(WHAT, __VA_ARGS__)
#define __LOGGER_FE_24(WHAT, X, ...) WHAT(24, X) __LOGGER_FE_23(WHAT, __VA_ARGS__)
#define __LOGGER_FE_25(WHAT, X, ...) WHAT(25, X) __LOGGER_FE_24(WHAT, __VA_ARGS__)
#define __LOGGER_FE_26(WHAT, X, ...) WHAT(26, X) __LOGGER_FE_25(WHAT, __VA_ARGS__)
#define __LOGGER_FE_27(WHAT, X, ...) WHAT(27, X) __LOGGER_FE_26(WHAT, __VA_ARGS__)
#define __LOGGER_FE_28(WHAT, X, ...) WHAT(28, X) __LOGGER_FE_27(WHAT, __VA_ARGS__)
#define __LOGGER_FE_29(WHAT, X, ...) WHAT(29, X) __LOGGER_FE_28(WHAT, __VA_ARGS__)
#define __LOGGER_FE_30(WHAT, X, ...) WHAT(30, X) __LOGGER_FE_29(WHAT, __VA_ARGS__)
#define __LOGGER_FE_31(WHAT, X, ...) WHAT(31, X) __LOGGER_FE_30(WHAT, __VA_ARGS__)
#define __LOGGER_FE_32(WHAT, X, ...) WHAT(32, X) __LOGGER_FE_31(WHAT, __VA_ARGS__)

#define __LOGGER_GET_MACRO(_1,  _2,  _3,  _4,  _5,  _6,  _7,  _8,	\
			   _9,  _10, _11, _12, _13, _14, _15, _16,	\
			   _17, _18, _19, _20, _21, _22, _23, _24,	\
			   _25, _26, _27, _28, _29, _30, _31, _32,	\
			   NAME,...) NAME				\

#define __LOGGER_FOR_EACH(ACTION,...)					\
	__LOGGER_GET_MACRO(__VA_ARGS__ __VA_OPT__(,)			\
	__LOGGER_FE_32, __LOGGER_FE_31, __LOGGER_FE_30, __LOGGER_FE_29,	\
	__LOGGER_FE_28, __LOGGER_FE_27, __LOGGER_FE_26, __LOGGER_FE_25,	\
	__LOGGER_FE_24,	__LOGGER_FE_23,	__LOGGER_FE_22,	__LOGGER_FE_21,	\
	__LOGGER_FE_20, __LOGGER_FE_19, __LOGGER_FE_18,	__LOGGER_FE_17,	\
	__LOGGER_FE_16, __LOGGER_FE_15, __LOGGER_FE_14, __LOGGER_FE_13,	\
	__LOGGER_FE_12, __LOGGER_FE_11, __LOGGER_FE_10, __LOGGER_FE_9,	\
	__LOGGER_FE_8,  __LOGGER_FE_7,  __LOGGER_FE_6,  __LOGGER_FE_5,	\
	__LOGGER_FE_4,  __LOGGER_FE_3,  __LOGGER_FE_2,  __LOGGER_FE_1,	\
	__LOGGER_FE_0)(ACTION __VA_OPT__(,) __VA_ARGS__)		\

#define __LOGGER_COUNT_PARAMS_SIZE(idx, arg) +sizeof(arg)
#define __LOGGER_CREATE_FIELD(idx, arg) typeof(arg) field_## idx;
#define __LOGGER_FILL_FIELD(idx, arg) .field_## idx = arg,

#define __LOGGER_LOG(LOG_LEVEL, FORMAT, ...) {						\
	if (LOG_LEVEL <= __log_level_dynamic) {						\
		/* calculate total size of passed params */				\
		const uint16_t params_size =						\
			(0 __LOGGER_FOR_EACH(__LOGGER_COUNT_PARAMS_SIZE, __VA_ARGS__));	\
		/* get handle to memory buffer */					\
		struct loggerMessage *const sink =					\
			(struct loggerMessage*)&__logger_buffer[0];			\
		/* push data */								\
		sink->log_level = (const uint8_t)LOG_LEVEL;				\
		sink->module_name = (const char *const)__log_module_name;		\
		sink->source_code_line = (uint16_t)__LINE__;				\
		sink->format_string = (const char *const)FORMAT;			\
		sink->params_size = (const uint16_t)params_size;			\
		/* create and fill struct with params */				\
		const struct __attribute__ ((__packed__)) loggerPayload {		\
			__LOGGER_FOR_EACH(__LOGGER_CREATE_FIELD, __VA_ARGS__)		\
		} params_list = {							\
			__LOGGER_FOR_EACH(__LOGGER_FILL_FIELD, __VA_ARGS__)		\
		};									\
		memcpy(sink->params_list, &params_list, params_size);			\
	}										\
}


/* -------------------------------------------- API -------------------------------------------- */
#define LOG_LEVEL_NONE	0
#define LOG_LEVEL_ERR	1
#define LOG_LEVEL_WRN	2
#define LOG_LEVEL_INF	3
#define LOG_LEVEL_DBG	4
#define LOG_LEVEL_ALL	5

#define LOGGER_REGISTER_MODULE(name, log_level)						\
	static const uint8_t __log_level_static = log_level;				\
	static const char *const LOGGER_MODULES_NAMES_SECTION __log_module_name = name;	\
	static uint8_t LOGGER_MODULES_LEVELS_SECTION __log_level_dynamic = log_level;

#define LOG(log_level, format, ...)					\
	if (log_level <= __log_level_static) {				\
		__LOGGER_LOG(log_level, format, __VA_ARGS__)		\
	}

#define LOG_ERR(format, ...)						\
	if (LOG_LEVEL_ERR <= __log_level_static) {			\
		__LOGGER_LOG(LOG_LEVEL_ERR, format, __VA_ARGS__)	\
	}

#define LOG_WRN(format, ...)						\
	if (LOG_LEVEL_WRN <= __log_level_static) {			\
		__LOGGER_LOG(LOG_LEVEL_WRN, format, __VA_ARGS__)	\
	}

#define LOG_INF(format, ...)						\
	if (LOG_LEVEL_INF <= __log_level_static) {			\
		__LOGGER_LOG(LOG_LEVEL_INF, format, __VA_ARGS__)	\
	}

#define LOG_DBG(format, ...)						\
	if (LOG_LEVEL_DBG <= __log_level_static) {			\
		__LOGGER_LOG(LOG_LEVEL_DBG, format, __VA_ARGS__)	\
	}
