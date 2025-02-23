#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} LogLevel;

/* Loglama sistemi için dosya acma */
int log_init(const char *filename);

/* Loglama işlemi yapıldıktan sonra dosyayı kapatma */
void log_close(void);

/* Belirtilen seviyede log mesajı yazma */
void log_message(LogLevel level, const char *format, ...);

#endif
