cmake_minimum_required(VERSION 3.13)

add_library(morse_utils
  morse_utils.c
)

target_include_directories(morse_utils PUBLIC
${CMAKE_CURRENT_LIST_DIR})