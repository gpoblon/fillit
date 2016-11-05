/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 23:24:22 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/05 14:22:13 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_set_tetri(t_data *tetri, size_t tmp_tdesc_count, t_input *count,
					char *s_input)
{
	char	*str_tdesc;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tetri->id = 'A' + tmp_tdesc_count;
	str_tdesc = ft_check_str_tdesc(s_input, count);
	ft_set_tetri_coord(str_tdesc, tetri);
	while (str_tdesc[i])
	{
		if (str_tdesc[i] == '#')
		{
			tetri->tetri_coord[j].x = (i % 5) - tetri->min.x;
			tetri->tetri_coord[j].y = (i / 5) - tetri->min.y;
			++j;
		}
		++i;
	}
	tetri->height = (tetri->max.y - tetri->min.y) + 1;
	tetri->width = (tetri->max.x - tetri->min.x) + 1;
	free(str_tdesc);
}

char	*ft_check_str_tdesc(char *s_input, t_input *count)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * TDESC_SIZE + 1);
	while (i < 20)
	{
		str[i] = s_input[count->buf_count];
		i++;
		count->buf_count++;
	}
	count->buf_count++;
	str[i] = '\0';
	ft_check_grid_valid(str);
	ft_check_connect(str);
	return (str);
}

void	ft_set_tetri_coord(char *str_tdesc, t_data *tetri)
{
	int		i;

	tetri->min.x = 3;
	tetri->min.y = 3;
	tetri->max.x = 0;
	tetri->max.y = 0;
	i = 0;
	while (str_tdesc[i])
	{
		if (str_tdesc[i] == '#')
		{
			if ((i % 5) < tetri->min.x)
				tetri->min.x = i % 5;
			if ((i / 5) < tetri->min.y)
				tetri->min.y = i / 5;
			if ((i % 5) > tetri->max.x)
				tetri->max.x = i % 5;
			if ((i / 5) > tetri->max.y)
				tetri->max.y = i / 5;
		}
		i++;
	}
}
