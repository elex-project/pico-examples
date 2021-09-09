cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(blink
    src/blink.c
)
pico_set_program_name(ProjectName "Blink")
pico_set_program_version(ProjectName "0.1.0")

pico_enable_stdio_usb(blink 1)
pico_enable_stdio_uart(blink 0)

pico_add_extra_outputs(blink)

target_link_libraries(blink pico_stdlib)