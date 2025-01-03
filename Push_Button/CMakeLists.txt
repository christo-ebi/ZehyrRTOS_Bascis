cmake_minimum_required(VERSION 3.22)
set(BOARD nucleo_f303re)

find_package(Zephyr)
project(Push_Button)

target_sources(app PRIVATE src/main.c)

