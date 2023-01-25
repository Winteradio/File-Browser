#ifndef __SUBLOG_H__
#define __SUBLOG_H__

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctime>

#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

#define LOG_WARN(str, ...) LOG_print("WARN", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_ERROR(str, ...) LOG_print("ERROR", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_INFO(str, ...) LOG_print("INFO", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_DEBUG(str, ...) LOG_print("DEBUG", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_TRACE(str, ...) LOG_print("TRACE", __FILENAME__, __FUNCTION__, __LINE__, str, ##__VA_ARGS__)
#define LOG_ALL(str, ...) LOG_print("ALL", __FILENAME__, __FUNCTION__, __LINE__)printf(str, ##__VA_ARGS__, "\n")

inline void LOG_print(const char* log_type,
	const char* filename,
	const char* funcname,
	const int linenum,
	const char* str, ...)
{
	time_t timer = time(NULL);
	tm time;
	localtime_s( &time, &timer );

	va_list List;
	va_start(List,str);
	printf("%d:%d:%d ", time.tm_hour, time.tm_min, time.tm_sec );
	printf("%s | ", log_type);
	printf("FILE : %s / FUNC : %s / NUM : %d | ", filename, funcname, linenum);
	vprintf(str,List);
	va_end(List);
	printf("\n");
}

#endif // __SUBLOG_H__