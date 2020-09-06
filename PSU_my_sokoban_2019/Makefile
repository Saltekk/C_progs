##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## c
##

SRC	=	lib/my/my_strlen.c \
		lib/my/lose.c \
		lib/my/win.c \
		lib/my/manage_box.c \
		lib/my/move_p.c \
		lib/my/reset.c \
		lib/my/state_elements.c \
		lib/my/fill_new_map.c \
		lib/my/display_map.c \
		lib/my/error_map.c\
		my_sokoban.c \

NAME	=	my_sokoban

all:    $(NAME)

$(NAME):
		gcc -g3 -lncurses -o $(NAME) $(SRC) -Wall -Wextra

clean:
	rm -f *~
	rm -f $(NAME)

fclean:	clean

re:	fclean all
