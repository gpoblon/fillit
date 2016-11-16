/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:01:06 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/16 15:11:50 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_tetri	*tetri;
	char	map[MAX_SQUARE * MAX_SQUARE];
	int		map_size;
	size_t	tdesc_count;

	tdesc_count = 0;
	tetri = NULL;
	if (argc != 2)
		ft_exit("error");
	tdesc_count = ft_get_tetri(argv[1], &tetri, tdesc_count);
	map_size = ft_fsqrt(tdesc_count);
	ft_init_map(map);
	while (!ft_solver(map, tetri, map_size))
	{
		ft_init_map(map);
		++map_size;
	}
	ft_print_map(map, map_size);
	return (0);
}
