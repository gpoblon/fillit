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

LIBFT	= ./libft/libft.a
LIBINC	= -I./libft
LIBLINK	= -L./libft -lft

SRCS_D	= ./srcs/
INC_D	= ./includes/
OBJS_D	= ./objs/

all:	obj libft $(NAME)

obj:
		mkdir -p $(OBJS_D)

libft:
		make re ./libft

$(OBJS_D)%.o:$(SRCS_D)%.c
		$(CC) $(C_FLAGS) $(LIBINC) -I$(INC_D) -o $@ -c $<

$(NAME): $(OBJS)
		$(CC) $(C_FLAGS) $(LIBLINK) -o $(NAME) $(OBJS) $(LIBFT)

clean:
		rm -rf $(OBJS_D)

fclean: clean
		rm -rf $(NAME)

re:		fclean all
