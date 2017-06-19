##
## Makefile for  in /home/mathias/Bureau/projet_epitech/synthèse/ADM_FASTAtools_2016
## 
## Made by Mathias
## Login   <mathias.descoin@epitech.eu@epitech.net>
## 
## Started on  Mon Jun 19 19:28:06 2017 Mathias
## Last update Mon Jun 19 19:29:40 2017 Mathias
##

SRC	=	test.c

OBJ	=	$(SRC:.c=.o)

NAME	=	FASTAtools

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
