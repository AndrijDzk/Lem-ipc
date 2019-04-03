cmake_minimum_required(VERSION 3.9)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(INC include)

set(COMMON_INC common)
set(COMMON_SDIR common)

set(NAME1 lemipc)
project(${NAME1} C)

set(LIBFT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libs/libft)
set(LIBFT_BINARY_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libs/libft/CMakeFiles)

set(SRCS1 src/main.c src/init.c)

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)

add_executable(${NAME1} ${SRCS1})
target_compile_definitions(${NAME1} PRIVATE KEYFILE="${CMAKE_CURRENT_SOURCE_DIR}/${INC}")
target_include_directories(${NAME1} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${INC}/)

add_subdirectory(${LIBFT_SOURCE_DIR} ${LIBFT_BINARY_DIR})

target_link_libraries(${NAME1} libft.a)
include_directories(${LIBFT_INC})
