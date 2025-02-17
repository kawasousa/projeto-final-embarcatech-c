#ifndef SD_LOGGER_H
#define SD_LOGGER_H

#include <stdbool.h>

// Inicializa o cartão microSD e o sistema de arquivos
bool sd_logger_init(void);

// Registra uma entrada de log no cartão microSD
void sd_logger_log(const char *log_entry);

#endif  // SD_LOGGER_H