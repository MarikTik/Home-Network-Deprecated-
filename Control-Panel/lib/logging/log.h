#ifndef LOGGING_H_
#define LOGGING_H_
#include <Arduino.h>
 
// NONE = 0
// ERROR = 1
// INFO = 2
// DEBUG = 3
// VERBOSE = 4
 
#if !defined(LOGGING_LEVEL) || LOGGING_LEVEL < 0 || LOGGING_LEVEL > 4
#define LOGGING_LEVEL 1
#endif 
 
#define FLASH_PROCESS(str) F(str)

#define ERROR_LOG_LABEL "[ERROR]: "
#define INFO_LOG_LABLE "[INFO]: "
#define DEBUG_LOG_LABLE "[DEBUG]: "
#define VERBOSE_LOG_LABLE "[VERBOSE] "

#define __LOG(str) Serial.print(FLASH_PROCESS(str))
#define __LOG_N(str) Serial.println(FLASH_PROCESS(str))
#define __LOG_F(str, ...) do{ Serial.printf(str, ##__VA_ARGS__); Serial.print('\n'); } while(0)

#define log_e_f(message, ...)
#define log_i_f(message, ...)
#define log_d_f(message, ...)
#define log_v_f(message, ...)

#define log_e(message)
#define log_i(message)
#define log_d(message)
#define log_v(message)

#if LOGGING_LEVEL > 0
#undef log_e
#undef log_e_f
#define log_e(message) do{ __LOG(ERROR_LOG_LABEL); __LOG_N(message);} while(0);
#define log_e_f(message, ...) do{ __LOG(ERROR_LOG_LABEL); __LOG(message, ##__VA_ARGS__);} while(0)
#endif

#if LOGGING_LEVEL > 1
#undef log_i
#undef log_i_f
#define log_i(message) do{ __LOG(INFO_LOG_LABLE); __LOG_N(message);} while(0);
#define log_i_f(message, ...) do{__LOG(INFO_LOG_LABLE); __LOG(message, ##__VA_ARGS__);} while(0)
#endif

#if LOGGING_LEVEL > 2
#undef log_d
#undef log_d_f
#define log_d(message) do{ __LOG(DEBUG_LOG_LABLE); __LOG_N(messssage);} while(0);
#define log_d_f(message, ...) do{ __LOG(DEBUG_LOG_LABLE); __LOG_F(message, ##__VA_ARGS__);} while(0)
#endif

#if LOGGING_LEVEL > 3
#undef log_v
#undef log_v_f
#define log_v(message) do{ __LOG(VERBOSE_LOG_LABLE); __LOG_N(messssage);} while(0);
#define log_v_f(message, ...) do{ __LOG(VERBOSE_LOG_LABLE); __LOG_F(message, ##__VA_ARGS__);} while(0)
#endif
 
 
#endif