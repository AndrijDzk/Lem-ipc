NAME1 = woody_woodpacker

CC = gcc
CFLAGS = -Wall -Werror -Wextra

ASM = nasm
AFLAGS = -f elf64

LD = ld
LDFLAGS =

INC = include

CFLAGS += -DKEYFILE=$(shell pwd)/$(INC)

SDIR = src

SRCS1 =	\
	main.c

SRCS1_R = $(SRCS1:%.c=$(SDIR)/%.c)

HEADERS1 = \
			return_codes.h \
			defines.h \
			lemipc.h \

HEADERS1_R = $(HEADERS1:%.h=$(INC)/%.h)

ODIR = Objects

OBJ1 = $(SRCS1:.c=.o)

OBJ1_R = $(OBJ1:%.o=$(ODIR)/%.o)

all : $(NAME1)

$(NAME1) : $(ODIR)/ $(OBJ1_R)
	make -C Libs/libft
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1_R) Libs/libft/libft.a

.PHONY: clean1 fclean1 dfclean1 re1 clean fclean re

clean1 :
	rm -f $(OBJ1_R)

fclean1 : clean1
	rm -f $(NAME1)

re1 : fclean1 $(NAME1)

clean: clean1

fclean : fclean1
	make fclean -C Libs/libft

re : re1

norm:
	make norm -C Libs/libft
	norminette $(SRCS1_R) $(HEADERS1_R)

add:
	make add -C Libs/libft
	git add $(SRCS1_R) $(HEADERS1_R)\
			$(SRCS2_R) \
			.gitignore Makefile CMakeLists.txt author

foo:
	echo $(CFLAGS)

$(ODIR)/ :
	mkdir -p $@

$(ODIR)/%.o : $(SDIR)/%.c $(HEADERS1_R)
	$(CC) $(CFLAGS) -c $< -o $@ -I libft/Includes -I $(INC)
