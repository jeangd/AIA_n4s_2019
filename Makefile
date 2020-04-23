##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC = main.c \
		my_str_to_word_tab.c \
		my_strcmp.c \

OBJ = $(SRC:.c=.o)

NAME = ai

CFLAGS = -g

INCLUDE = -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) $(INCLUDE)

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f *#
	rm -rf lib/my/*.o
	rm -rf lib/my/libmy.a
	rm -rf vgcore*

fclean: clean
	rm -f $(NAME)

re:	fclean all
