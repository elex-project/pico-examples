cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)

project(datatypes C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(datatypes
    src/datatypes.c
)

pico_set_program_name(datatypes "Data Types")
pico_set_program_version(datatypes "0.1.0")

pico_enable_stdio_usb(datatypes 1) # 표준 출력을 USB로
pico_enable_stdio_uart(datatypes 0) # 표준 출력을 UART로, 안함.

pico_add_extra_outputs(datatypes)

target_link_libraries(datatypes pico_stdlib)
