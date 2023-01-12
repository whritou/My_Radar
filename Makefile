##
## EPITECH PROJECT, 2022
## Makefiles
## File description:
## MakeFiles
##

SRC	=	$(wildcard lib/my/*.c file/*.c)

OBJ	=	$(SRC:.c=.o)

CFLAGS = -W -Wall -Wextra -g2 -O2

NAME = libmy.a
NAMED =	my_radar

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(NAME)

$(NAME): $(OBJ)
	mkdir -p includes
	cp lib/my/my.h includes/
	ar rc $(NAME) $(OBJ)
	gcc -o $(NAMED) file/main.c -I includes/ -L. -lmy $(CSFML) $(CFLAGS) -g -lm

clean:
	rm -f $(wildcard lib/my/.# lib/my/*~)
	rm -f $(wildcard file/.# file/*~)
	rm -f $(wildcard .# *~)
	rm -f $(wildcard vgcore.*)
	rm -f $(OBJ)

fclean :	clean
	rm -f $(NAME)
	rm -f $(NAMED)
	rm -f $(OBJ)

re:	fclean all
