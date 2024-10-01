cmake_minimum_required(VERSION 3.22)
set(BOARD stm32_min_dev@blue)

find_package(Zephyr)
project(Blink_portable)

target_sources(app PRIVATE src/main.c)

