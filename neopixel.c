#include "neopixel.h"
#include "pico/stdlib.h"

#define NEOPIXEL_PIN 7
#define NUM_LEDS 25

// Função para enviar cor para todos os LEDs (ex: vermelho)
// Em uma aplicação real, implemente a rotina de transmissão para os WS2812B (via PIO ou bit-banging).
static void setNeopixelColor(uint8_t r, uint8_t g, uint8_t b) {
    // Exemplo simplificado: simulação sem implementação real.
}

void neopixel_init(void) {
    gpio_init(NEOPIXEL_PIN);
    gpio_set_dir(NEOPIXEL_PIN, GPIO_OUT);
    // Inicializa a matriz com todos os LEDs apagados
    setNeopixelColor(0, 0, 0);
}

void blinkNeopixelRed(uint8_t count, uint16_t delay_ms) {
    for(uint8_t i = 0; i < count; i++) {
        // Acende todos os LEDs em vermelho
        setNeopixelColor(255, 0, 0);
        sleep_ms(delay_ms);
        // Apaga os LEDs
        setNeopixelColor(0, 0, 0);
        sleep_ms(delay_ms);
    }
}
