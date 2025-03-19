#include <stdio.h>
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include "../include/logger.h"

/* Varsayilan olarak loglama icin stdout kullanilir. */
static FILE *log_file = NULL;

int log_init(const char *filename) {
    if (filename == NULL || strlen(filename) == 0) {
        log_file = stdout;
        return 0;
    }
    
    log_file = fopen(filename, "a");
    if (!log_file) {
        log_file = stdout;
        return -1;
    }
    return 0;
}

void log_close(void) {
    /* Eger log_file stdout degilse, kapat */
    if (log_file && log_file != stdout) {
        fclose(log_file);
    }
    log_file = stdout;  // Default degere geri don
}

void log_message(LogLevel level, const char *format, ...) {
    if (!log_file) {
        log_file = stdout;
    }

    const char *level_str;
    switch (level) {
        case LOG_LEVEL_DEBUG:   level_str = "DEBUG"; break;
        case LOG_LEVEL_INFO:    level_str = "INFO"; break;
        case LOG_LEVEL_WARNING: level_str = "WARNING"; break;
        case LOG_LEVEL_ERROR:   level_str = "ERROR"; break;
        default:                level_str = "UNKNOWN"; break;
    }

    time_t now = time(NULL);
    char time_str[20];
    struct tm *tm_info = localtime(&now);
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(log_file, "[%s] [%s] ", time_str, level_str);

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    fprintf(log_file, "\n");
    fflush(log_file);
}
