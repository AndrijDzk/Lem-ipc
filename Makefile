NAME1 = lemipc

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LDFLAGS = -pthread

INC = include

SDIR = src

SRCS1 = \
	main.c \
	init.c \
	receive_thread.c \
	check_adjacent_cells.c \
	join_game.c \
	fill_sembuf.c \
	lemipc_update_signal.c \
	terminate.c \
	print_playfield.c \
	send_thread.c \
	move.c

SRCS1_R = $(SRCS1:%.c=$(SDIR)/%.c)

HEADERS1 = \
			return_codes.h \
			defines.h \
			lemipc_typedefs.h \
			lemipc.h

HEADERS1_R = $(HEADERS1:%.h=$(INC)/%.h)

ODIR = Objects

OBJ1 = $(SRCS1:%.c=%.o)
OBJ1_R = $(OBJ1:%.o=$(ODIR)/%.o)

all : $(ODIR)/ $(NAME1)

$(NAME1) : $(ODIR)/ $(OBJ1_R)
	make -C Libs/libft
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1_R) Libs/libft/libft.a $(LDFLAGS)

.PHONY: clean1 fclean1 re1 clean2 fclean2 re2 clean fclean re

clean1 :
	rm -f $(OBJ1_R)

fclean1 : clean1
	rm -f $(NAME1)

re1 : fclean1 $(NAME1)

clean2 :
	rm -f $(OBJ2_R)

fclean2 : clean2
	rm -f $(NAME2)

re2 : fclean2 $(NAME2)

clean : clean1 clean2

fclean : clean
	rm -f $(NAME1) $(NAME2)

re : fclean all

norm:
	make norm -C Libs/libft
	norminette $(SRC1_R) $(HEADERS1_R)

add:
	make add -C Libs/libft
	git add $(SRCS1_R) $(HEADERS1_R)\
		.gitignore Makefile CMakeLists.txt author

test1: $(NAME1)
	./$(NAME1)

$(ODIR)/ :
	mkdir -p $@

$(ODIR)/%.o : $(SDIR)/%.c $(HEADERS1_R)
	$(CC) $(CFLAGS) -c $< -o $@ -I Libs/libft/Includes -I $(INC)
