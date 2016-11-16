/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 21:13:34 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/16 15:15:36 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

# define MAX_SQUARE 16
# define BUFF_SIZE	21

typedef struct		s_tetri_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_tetri
{
	char			id;
	t_coord			min;
	t_coord			max;
	t_coord			tetri_coord[4];
	t_coord			pos;
	int				width;
	int				height;
	struct s_tetri	*next;
}					t_tetri;

size_t				ft_get_tetri(char *filename, t_tetri **tetri,
					size_t tdesc_count);
int					ft_read_fd(int fd, char *buffer);
size_t				ft_check_grid_valid(char *buffer);
void				ft_check_connect(char *buffer);
void				ft_set_tetri(t_tetri **bgn_tetri, char *buffer,
					size_t tdesc_count);
t_tetri				*ft_new_tetri(void);
void				ft_set_tetri_coord(char *buffer, t_tetri *tetri);
void				ft_push_back_tetri(t_tetri **bgn_tetri, t_tetri *tetri);
int					ft_fsqrt(size_t tdesc_count);
void				ft_init_map(char *map);
int					ft_solver(char *map, t_tetri *tetri, int map_size);
int					ft_valid_pos(char *map, t_tetri *tetri);
void				ft_set_tetri_map(char *map, t_tetri *tetri);
void				ft_delete_tetri(char *map, t_tetri *tetri);
void				ft_print_map(char *map, int map_size);

#endif
