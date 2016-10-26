/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 12:51:58 by gpoblon           #+#    #+#             */
/*   Updated: 2016/10/25 02:37:23 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_init_map(char *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < MAX_SQUARE)
	{
		j = 0;
		while (j < MAX_SQUARE)
		{
			map[(i * MAX_SQUARE) + j] = '.';
			j++;
		}
		i++;
	}
}

void	ft_print_map(char *map, size_t map_size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map_size)
	{
		j = 0;
		while (j < map_size)
		{
			ft_putchar(map[(i * MAX_SQUARE) + j]);
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}
