#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include "pico/stdlib.h"

// Função para inicializar a matriz de LEDs (WS2812B) no GPIO7
void neopixel_init(void);

// Função para piscar a matriz de LEDs em vermelho
// count: número de piscadas, delay_ms: intervalo entre as piscadas em milissegundos
void blinkNeopixelRed(uint8_t count, uint16_t delay_ms);

#endif  // NEOPIXEL_H