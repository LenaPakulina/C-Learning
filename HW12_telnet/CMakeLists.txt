cmake_minimum_required(VERSION 3.5)

project(HW_telnet LANGUAGES C)

add_executable(HW_telnet main.c)
target_compile_options(HW_telnet PRIVATE -Wall -Wextra -Wpedantic -std=gnu11)
