NAME	=	fillit

SRC		=	main.c \
			reader.c \
			check.c \
			tetri.c \
			map.c \
			solver.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc -Wall -Wextra -Werror

LIBFT	= ./libft/libft.a
LIBLINK	= -L./libft -lft

all: $(NAME)

$(NAME): $(OBJ)
		make -C ./libft
		gcc $(LIBLINK) -o $(NAME) $(OBJ)

clean:
		rm -rf $(OBJ)
		make -C ./libft clean

fclean:	clean
		rm -rf $(NAME)
		make -C ./libft fclean

re:		fclean all

.PHONY: clean
