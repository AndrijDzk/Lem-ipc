NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra

INC = Includes

SDIR = Srcs

SRCS = \
		ft_tolower.c\
		ft_isdigit.c\
		ft_atoi.c\
		ft_itoa.c\
		ft_bzero.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_strchr.c\
		ft_power.c\
		ft_find_char.c\
		ft_strcpy.c\
		ft_strdup.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strsplit.c\
		ft_memcmp.c\
		ft_memset.c\
		ft_memdup.c\
		list.c\
		t_list_push_front.c\
		t_list_clear.c\
		free_2darr.c\
		get_next_line.c\
		ft_printf/ft_strlen.c\
		ft_printf/ft_flag_funcs.c\
		ft_printf/ft_flags.c\
		ft_printf/ft_int_arr_prefix.c\
		ft_printf/ft_int_recall_funcs.c\
		ft_printf/ft_print_memory.c\
		ft_printf/ft_printf.c\
		ft_printf/ft_fp_arr_init.c\
		ft_printf/ft_put_float.c\
		ft_printf/ft_put_float_nbr_base.c\
		ft_printf/ft_put_int.c\
		ft_printf/ft_put_nbr_base.c\
		ft_printf/ft_put_tab.c\
		ft_printf/ft_putchar.c\
		ft_printf/ft_recall.c\
		ft_printf/ft_scan.c\
		ft_printf/ft_scan_funcs.c\
		ft_printf/ft_print_memory_split_condition.c

SRCS_R = $(SRCS:%.c=$(SDIR)/%.c)

ODIR = Objects

OBJ = $(SRCS:%.c=%.o)

OBJ_R = $(OBJ:%.o=$(ODIR)/%.o)

HEADERS = ft_printf/libconvfuncs.h\
		ft_printf/libflagfuncs.h\
		ft_printf/libprintf.h\
		ft_printf/librecall.h\
		ft_printf/flags.h\
		list.h\
		get_next_line.h\
		libft.h

HEADERS_R = $(HEADERS:%.h=$(INC)/%.h)

all : $(ODIR)/ $(ODIR)/ft_printf/ $(NAME)

$(NAME) : $(OBJ_R)
	ar rc $(NAME) $(OBJ_R)

debug :
	mkdir -p debug
	cd debug
	gcc -g -c $(SRCS_R:%.c=../%.c)

clean :
	rm -f $(OBJ_R)

fclean : clean
	rm -f $(NAME)

dclean :
	rm -f *.o

all_to_dst: $(OBJ_R)
	ar rc $(DST) $(OBJ)

re : fclean all

norm:
	norminette $(SRCS_R) $(HEADERS_R)

add:
	git add $(SRCS_R) $(HEADERS_R) Makefile CMakeLists.txt

$(ODIR)/ :
	mkdir -p $@

$(ODIR)/ft_printf/ :
	mkdir -p $@

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC) -I $(INC)/ft_printf
