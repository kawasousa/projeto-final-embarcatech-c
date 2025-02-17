#include "pico/stdlib.h"
#include "hardware/adc.h"
#include "neopixel.h"
#include "sd_logger.h"
#include <stdio.h>
#include <time.h>

#define MIC_ADC_PIN 28
#define SOUND_THRESHOLD 2000

int main() {
    // Inicialização padrão
    stdio_init_all();
    sleep_ms(1000);

    // Inicialização do ADC para o microfone
    adc_init();
    adc_gpio_init(MIC_ADC_PIN);
    // Para o pino 28, que corresponde ao ADC2 no RP2040
    adc_select_input(2);

    // Inicializar a matriz de LEDs (Neopixel) no GPIO7
    neopixel_init();

    // Inicializar o módulo microSD para registro de eventos
    if (!sd_logger_init()) {
        printf("Erro ao inicializar o microSD!\n");
        return 1;
    }

    while (1) {
        // Leitura do valor do microfone
        uint16_t adc_val = adc_read();
        // Debug: mostrar valor lido
        printf("ADC Value: %d\n", adc_val);

        // Se o valor ultrapassar o limiar, aciona alerta visual e registra o evento
        if (adc_val >= SOUND_THRESHOLD) {
            // Pisca a matriz de LEDs em vermelho 3 vezes
            blinkNeopixelRed(3, 200); // 3 piscadas com 200ms de intervalo

            // Obter o timestamp atual
            time_t raw_time;
            struct tm *time_info;
            char timestamp[20];

            time(&raw_time);                    // Obtém o tempo atual
            time_info = localtime(&raw_time);   // Converte para a hora local

            // Formatar o timestamp como YYYY-MM-DD HH:MM:SS
            strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", time_info);

            // Cria uma mensagem de log com o timestamp
            char log_entry[150];
            snprintf(log_entry, sizeof(log_entry), "ALERTA: %s - Nível de som elevado: %d\n", timestamp, adc_val);

            // Logar no arquivo
            sd_logger_log(log_entry);
        }

        sleep_ms(200);
    }
    return 0;
}