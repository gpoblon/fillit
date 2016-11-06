/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:01:06 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/06 16:50:28 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_input	*count;
	char	*s_input;

	if (argc != 2)
		ft_exit("error");
	count = ft_memalloc(sizeof(t_input));
	s_input = ft_input_to_str(argv[1], count);
	ft_main_solver(count, s_input);
	free(s_input);
	free(count);
	return (0);
}

void	ft_main_solver(t_input *count, char *s_input)
{
	size_t	tmp_tdesc_count;
	t_data	*tetri;
	char	map[MAX_SQUARE * MAX_SQUARE];
	int		map_size;

	tmp_tdesc_count = 0;
	tetri = ft_memalloc(sizeof(t_data) * count->tdesc_count);
	while (tmp_tdesc_count < count->tdesc_count - 1)
	{
		ft_set_tetri(&tetri[tmp_tdesc_count], tmp_tdesc_count, count, s_input);
		++tmp_tdesc_count;
	}
	map_size = ft_fsqrt(count);
	ft_init_map(map);
	while (!ft_solver(map, &tetri[0], map_size))
	{
		ft_init_map(map);
		++map_size;
	}
	ft_print_map(map, map_size);
	free(tetri);
}
