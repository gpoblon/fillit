NAME	=	fillit

SRC		=	main.c \
			check_input.c \
			get_tetri_coord.c \
			input_to_tab.c \
			tetri_map.c \
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
