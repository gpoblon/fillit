/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 18:01:06 by gpoblon           #+#    #+#             */
/*   Updated: 2016/10/26 21:58:05 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	t_data	*tetri;
	t_input	*count;
	size_t	tmp_tdesc_count;
	char	*s_input;
	char	map[MAX_SQUARE * MAX_SQUARE];
	size_t	map_size;

	if (argc != 2)
		ft_exit("number of arg error");
	count = (t_input *)malloc(sizeof(t_input));
	CHECKPV0(count)
	s_input = ft_input_to_str(argv[1], count);
	tmp_tdesc_count = 0;
	tetri = (t_data *)malloc(sizeof(t_data) * count->tdesc_count);
	while (tmp_tdesc_count < count->tdesc_count - 1)
	{
		ft_set_tetri(&tetri[tmp_tdesc_count], tmp_tdesc_count, count, s_input);
		++tmp_tdesc_count;
	}
	free(s_input);
	free(count);
	map_size = (tetri[0].height > tetri[0].width) ? tetri[0].height :
				tetri[0].width;
	ft_init_map(map);
	while (!ft_solver(map, &tetri[0], map_size))
	{
		ft_init_map(map);
		map_size++;
	}
	ft_print_map(map, map_size);
	return (0);
}

// Process :
//
// I declare a struct called count which allows me both to check input validity and to set a right size to the strings I work on.
// 1. Reading a first time fd to get the hole size / tdesc count.
// 2. Reading a second time to create a string (s_input) of the hole fd. A first pass check is done at this moment (buffer size & every char).
// Remember that s_data struct contains every information I need to store about each tdesc, beginning with its id, its position, its coords (defined by 4 x/y points in t_coord struct).
// 3. A new string is created based on the first but isolating tdesc (deleting \n between every tdesc) within tdescs validity is checked.
// 4. An id is attributed to each tdesc and every of its full boxes positions are stored. tetri[n] represents the n tetri stored and defined as 4 X t_coord[x, y].
// Reminder : ft_set_tetri_coord is a min/max function allowing me to ignore position of a tetri in its grid (because its position is at the very least irrelevant to solve fillit) in order to get absolute coordinates of that same tetri.
// 5. Smallest map possible is initialised and fullfiled by '.'s.
// 6. This is the last step before printing my solved fillit : if all tetris can t be placed in this square, I try again with a +1 size square until it finally works.
//
// As for the solver itself : if the 4 boxes of the tetri which is getting placed are not filled yet, they are placed in the final grid (most upper-left position possible), and the action is repeated as many times as there are still tdesc left to place.
