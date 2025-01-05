cmake_minimum_required(VERSION 3.22)
set(BOARD nucleo_f303re)

find_package(Zephyr)
project(DS18B20_GPIO)

target_sources(app PRIVATE src/main.c)

