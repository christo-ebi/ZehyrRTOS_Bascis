cmake_minimum_required(VERSION 3.22)
set(BOARD stm32_min_dev_blue)

find_package(Zephyr)
project(hello_world_Blink)

target_sources(app PRIVATE src/main.c)

