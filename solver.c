/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 10:28:30 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/16 16:16:25 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_solver(char *map, t_tetri *tetri, int map_size)
{
	if (tetri == NULL)
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
				if (ft_solver(map, tetri->next, map_size))
					return (1);
				ft_delete_tetri(map, tetri);
			}
			tetri->pos.x++;
		}
		tetri->pos.y++;
	}
	return (0);
}

int		ft_valid_pos(char *map, t_tetri *tetri)
{
	size_t		i;

	i = 0;
	while (i < 4)
	{
		if (map[(tetri->tetri_coord[i].y + tetri->pos.y) * MAX_SQUARE +
		tetri->tetri_coord[i].x + tetri->pos.x] != '.')
			return (0);
		i++;
	}
	return (1);
}

void	ft_set_tetri_map(char *map, t_tetri *tetri)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		map[(tetri->tetri_coord[i].y + tetri->pos.y) * MAX_SQUARE +
		tetri->tetri_coord[i].x + tetri->pos.x] = tetri->id;
		i++;
	}
}

void	ft_delete_tetri(char *map, t_tetri *tetri)
{
	size_t	i;

	i = 0;
	while (i < 4)
	{
		map[(tetri->tetri_coord[i].y + tetri->pos.y) * MAX_SQUARE +
		tetri->tetri_coord[i].x + tetri->pos.x] = '.';
		i++;
	}
}
