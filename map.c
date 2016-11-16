/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 12:51:58 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/16 15:52:22 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_fsqrt(size_t tdesc_count)
{
	size_t	n;

	n = 1;
	while (n * n < 4 * tdesc_count)
		++n;
	return (n);
}

void	ft_init_map(char *map)
{
	size_t	i;

	i = 0;
	while (i < MAX_SQUARE * MAX_SQUARE)
	{
		map[i] = '.';
		i++;
	}
}

void	ft_print_map(char *map, int map_size)
{
	int		i;
	int		j;

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
