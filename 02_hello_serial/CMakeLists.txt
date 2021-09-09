cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(hello C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(hello
    src/hello.c
)

pico_set_program_name(hello "Hello Serial")
pico_set_program_version(hello "0.1.0")

pico_enable_stdio_usb(hello 1) # 표준 출력을 USB로
pico_enable_stdio_uart(hello 0) # 표준 출력을 UART로, 안함.

pico_add_extra_outputs(hello)

target_link_libraries(hello pico_stdlib)
