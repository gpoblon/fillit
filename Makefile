NAME	=	fillit

SRCS	=	main.c \
			input_to_tab.c \
			check_input.c \
			get_tetri_coord.c \
			tetri_map.c \
			solver.c \

OBJS	= $(addprefix $(OBJS_D),$(SRCS:.c=.o))

CC		= gcc
C_FLAGS = -Wall -Werror -Wextra

LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

SRCS_D	= ./srcs/
INC_D	= -I./includes/
OBJS_D	= ./objs/

all:	$(NAME)

obj:
		mkdir -p $(OBJS_D)

lft:
		make -C ./libft

$(OBJS_D)%.o:$(SRCS_D)%.c
		$(CC) $(C_FLAGS) $(LIBINC) $(INC_D) -o $@ -c $<

$(NAME): obj $(OBJS) lft
		$(CC) $(C_FLAGS) $(LIBLINK) -o $(NAME) $(OBJS)

clean:
		rm -rf $(OBJS_D)
		make -C ./libft clean

fclean: clean
		rm -rf $(NAME)
		make -C ./libft fclean

re:		fclean all

.PHONY: clean
