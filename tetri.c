/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tetri_coord.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 23:24:22 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/16 15:11:51 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*ft_new_tetri(void)
{
	t_tetri		*tetri;

	tetri = (t_tetri *)malloc(sizeof(*tetri));
	if (tetri)
		tetri->next = NULL;
	return (tetri);
}

void	ft_push_back_tetri(t_tetri **bgn_tetri, t_tetri *tetri)
{
	t_tetri		*list;

	list = *bgn_tetri;
	if (!list)
	{
		list = tetri;
		*bgn_tetri = list;
	}
	else
	{
		while (list->next)
			list = list->next;
		list->next = tetri;
	}
}

void	ft_set_tetri(t_tetri **bgn_tetri, char *buffer, size_t tdesc_count)
{
	size_t	i;
	size_t	j;
	t_tetri	*tetri;

	i = 0;
	j = 0;
	tetri = ft_new_tetri();
	tetri->id = 'A' + tdesc_count;
	ft_set_tetri_coord(buffer, tetri);
	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			tetri->tetri_coord[j].x = (i % 5) - tetri->min.x;
			tetri->tetri_coord[j].y = (i / 5) - tetri->min.y;
			++j;
		}
		++i;
	}
	tetri->height = (tetri->max.y - tetri->min.y) + 1;
	tetri->width = (tetri->max.x - tetri->min.x) + 1;
	ft_push_back_tetri(bgn_tetri, tetri);
}

void	ft_set_tetri_coord(char *buffer, t_tetri *tetri)
{
	int		i;

	tetri->min.x = 3;
	tetri->min.y = 3;
	tetri->max.x = 0;
	tetri->max.y = 0;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '#')
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
