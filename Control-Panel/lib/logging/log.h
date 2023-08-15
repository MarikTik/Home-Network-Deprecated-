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

#define __LOG(message, ...) Serial.println(FLASH_PROCESS(message), ##__VA_ARGS__)

#define log_e(message, ...)
#define log_i(message, ...)
#define log_d(message, ...)
#define log_v(message, ...)

#if LOGGING_LEVEL > 0
#undef log_e
#define log_e(message, ...) do{Serial.print(FLASH_PROCESS(ERROR_LOG_LABEL)); __LOG(message, ##__VA_ARGS__);} while(0)
#endif

#if LOGGING_LEVEL > 1
#undef log_i
#define log_i(message, ...) do{Serial.print(FLASH_PROCESS(INFO_LOG_LABLE)); __LOG(message, ##__VA_ARGS__);} while(0)
#endif

#if LOGGING_LEVEL > 2
#undef log_d
#define log_d(message, ...) do{Serial.print(FLASH_PROCESS(DEBUG_LOG_LABLE)); __LOG(message, ##__VA_ARGS__);} while(0)
#endif

#if LOGGING_LEVEL > 3
#undef log_v
#define log_v(message, ...) do{Serial.print(FLASH_PROCESS(VERBOSE_LOG_LABLE)); __LOG(message, ##__VA_ARGS__);} while(0)
#endif
 
 
#endif