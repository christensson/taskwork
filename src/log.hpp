#ifndef _LOG_HPP_
#define _LOG_HPP_

#include <stdio.h>

#ifdef ENABLE_LOGGING
#define LOG_DEBUG(...) printf("[DBG ] " __VA_ARGS__)
#define LOG_INFO(...)  printf("[INFO] " __VA_ARGS__)
#define LOG_WARN(...)  printf("[WARN] " __VA_ARGS__)
#define LOG_ERROR(...) printf("[ERR ] " __VA_ARGS__)
#else
#define LOG_DEBUG(...)
#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#endif

#endif
