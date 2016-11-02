/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 21:13:34 by gpoblon           #+#    #+#             */
/*   Updated: 2016/10/27 15:23:05 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft.h"

# define		TDESC_SIZE 20
# define		MAX_TETRIS 26
# define		MAX_SQUARE 16

typedef struct	s_input_check
{
	float		tdesc_count;
	size_t		buf_size;
	size_t		buf_count;
}				t_input;

typedef struct	s_tetri_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_tetri_data
{
	char		id;
	t_coord		min;
	t_coord		max;
	t_coord		tetri_coord[4];
	t_coord		pos;
	int			width;
	int			height;
}				t_data;

char			*ft_input_to_str(char *filename, t_input *count);
char			*ft_get_str(char *filename, t_input *count);

void			ft_set_tetri(t_data *tetri, size_t tmp_tdesc_count, t_input *count, char *s_input);
char			*ft_check_str_tdesc(char *s_input, t_input *count);
void			ft_check_grid_valid(char *str);
void			ft_check_connect(char *str);
void			ft_set_tetri_coord(char *str_tdesc, t_data *tetri);

void			ft_init_map(char *map);
int				ft_solver(char *map, t_data *tetri, int map_size);
void			ft_set_tetri_map(char *map, t_data *tetri);
void			ft_delete_tetri(char *map, t_data *tetri);
void			ft_print_map(char *map, int map_size);
int				ft_valid_pos(char *map, t_data *tetri);


#endif
