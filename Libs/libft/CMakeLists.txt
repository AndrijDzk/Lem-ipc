cmake_minimum_required(VERSION 3.9)
FUNCTION(PREPEND var prefix)
   SET(listVar "")
   FOREACH(f ${ARGN})
      LIST(APPEND listVar "${prefix}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(NAME libft.a)
project(${NAME} C)

set(INC Includes)

set(LIBFT_INC ${CMAKE_CURRENT_SOURCE_DIR}/${INC} PARENT_SCOPE)

set(SDIR Srcs)

set(SOURCES
		"ft_tolower.c"
		"ft_isdigit.c"
		"ft_atoi.c"
		"ft_itoa.c"
		"ft_bzero.c"
		"ft_strcmp.c"
		"ft_strncmp.c"
		"ft_strchr.c"
		"ft_power.c"
		"ft_find_char.c"
		"ft_strcpy.c"
		"ft_strdup.c"
		"ft_strsub.c"
		"ft_strjoin.c"
		"ft_strsplit.c"
		"ft_memcmp.c"
		"ft_memset.c"
		"ft_memdup.c"
		"list.c"
		"t_list_push_front.c"
		"t_list_clear.c"
		"free_2darr.c"
		"get_next_line.c"
		"ft_printf/ft_strlen.c"
		"ft_printf/ft_flag_funcs.c"
		"ft_printf/ft_flags.c"
		"ft_printf/ft_int_arr_prefix.c"
		"ft_printf/ft_int_recall_funcs.c"
		"ft_printf/ft_print_memory.c"
		"ft_printf/ft_printf.c"
		"ft_printf/ft_fp_arr_init.c"
		"ft_printf/ft_put_float.c"
		"ft_printf/ft_put_float_nbr_base.c"
		"ft_printf/ft_put_int.c"
		"ft_printf/ft_put_nbr_base.c"
		"ft_printf/ft_put_tab.c"
		"ft_printf/ft_putchar.c"
		"ft_printf/ft_recall.c"
		"ft_printf/ft_scan.c"
		"ft_printf/ft_scan_funcs.c"
		"ft_printf/ft_print_memory_split_condition.c")

PREPEND(SOURCES_REL ${SDIR} ${SOURCES})

set(CMAKE_C_FLAGS "-Wall -Werror -Wextra")

message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR} CACHE PATH "Executable output dir" FORCE)
message("EXECUTABLE_OUTPUT_PATH - ${EXECUTABLE_OUTPUT_PATH}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${INC})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/${INC}/ft_printf)
add_library(${NAME} ${SOURCES_REL} Srcs/ft_memmove.c)
