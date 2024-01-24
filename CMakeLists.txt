cmake_minimum_required(VERSION 3.16)

project(AVRExample)

include_directories(include)

file(GLOB sources src/*.c)
add_avr_executable(avr-example ${sources})
