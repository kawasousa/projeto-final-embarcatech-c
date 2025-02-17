# Generated Cmake Pico project file

cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.1.0)
set(toolchainVersion 13_3_Rel1)
set(picotoolVersion 2.1.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================
set(PICO_BOARD pico_w CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(SoundMonitoring C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Add executable. Default name is the project name, version 0.1
add_executable(SoundMonitoring main.c neopixel.c sd_logger.c)

add_subdirectory(${CMAKE_CURRENT_LIST_DIR}/libs/RP2040-WS2812B-Animation)

pico_set_program_name(SoundMonitoring "SoundMonitoring")
pico_set_program_version(SoundMonitoring "0.1")

# Modifique as linhas abaixo para habilitar/desabilitar a saída via UART/USB
pico_enable_stdio_uart(SoundMonitoring 0)
pico_enable_stdio_usb(SoundMonitoring 1)

# Adiciona a biblioteca padrão ao build
target_link_libraries(SoundMonitoring
    pico_stdlib
    hardware_adc
    ws2812b_animation
)

# Adiciona os diretórios de includes padrão
target_include_directories(SoundMonitoring PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
)

pico_add_extra_outputs(SoundMonitoring)

set(TARGET_NAME "ws2812b_animation")

if (NOT TARGET ${TARGET_NAME})
    add_library(${TARGET_NAME} INTERFACE)

    target_sources(${TARGET_NAME} INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/libs/RP2040-WS2812B-Animation/ws2812b_animation.c
        ${CMAKE_CURRENT_LIST_DIR}/libs/RP2040-WS2812B-Animation/inc/utf8-iterator/source/utf-8.c
    )

    target_include_directories(${TARGET_NAME} INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}
        ${CMAKE_CURRENT_LIST_DIR}/libs/RP2040-WS2812B-Animation/inc/
        ${CMAKE_CURRENT_LIST_DIR}/libs/RP2040-WS2812B-Animation/inc/CP0-EU/
        ${CMAKE_CURRENT_LIST_DIR}/libs/RP2040-WS2812B-Animation/inc/utf8-iterator/source/
    )

    pico_generate_pio_header(${TARGET_NAME} ${CMAKE_CURRENT_LIST_DIR}/libs/RP2040-WS2812B-Animation/ws2812.pio)

    target_link_libraries(${TARGET_NAME} INTERFACE
        pico_stdlib
        hardware_pio
    )
endif()