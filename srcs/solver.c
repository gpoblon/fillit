/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 10:28:30 by gpoblon           #+#    #+#             */
/*   Updated: 2016/10/26 22:02:36 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solver(char *map, t_data *tetri, size_t map_size)
{
	size_t	i;
	if (tetri->id == 0)
		return (1);

	tetri->pos.y = 0;
	while (tetri->pos.y <= map_size - tetri->height)
	{
		tetri->pos.x = 0;
		while (tetri->pos.x <= map_size - tetri->width)
		{
			if (ft_valid_pos(map, tetri))
			{
				ft_set_tetri_map(map, tetri);
				if (ft_solver(map, tetri + 1, map_size))
					return (1);
				i = 0;
				while (i < 4)
				{
					map[(tetri->tetri_coord[i].y + tetri->pos.y) * MAX_SQUARE + tetri->tetri_coord[i].x + tetri->pos.x] = '.';
					i++;
				}
			}
			tetri->pos.x++;
		}
		tetri->pos.y++;
	}
	return (0);
}


void	ft_set_tetri_map(char *map, t_data *tetri)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		map[(tetri->tetri_coord[i].y + tetri->pos.y) * MAX_SQUARE + tetri->tetri_coord[i].x + tetri->pos.x] = tetri->id;
		i++;
	}
}

int		ft_valid_pos(char *map, t_data *tetri)
{
	size_t		i;

	i = 0;
	while (i < 4)
	{
		if (map[(tetri->tetri_coord[i].y + tetri->pos.y) * MAX_SQUARE + tetri->tetri_coord[i].x + tetri->pos.x] != '.')
			return (0);
		i++;
	}
	return (1);
}
