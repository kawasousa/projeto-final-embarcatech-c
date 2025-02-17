#include "sd_logger.h"
#include "pico/stdlib.h"
#include <stdio.h>
#include <string.h>

// Simulação de registro no microSD utilizando um arquivo local.
// Em uma implementação real, inicialize o SPI, FATFS, etc.
static FILE *log_file = NULL;

bool sd_logger_init(void) {
    // Abre ou cria o arquivo "log.txt" para adicionar registros
    log_file = fopen("log.txt", "a");
    if (log_file == NULL) {
        return false;
    }
    return true;
}

void sd_logger_log(const char *log_entry) {
    if (log_file != NULL) {
        fprintf(log_file, "%s", log_entry);
        fflush(log_file);
    }
}