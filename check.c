/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 15:19:38 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/16 15:25:00 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_check_grid_valid(char *buffer)
{
	size_t	pound_c;
	size_t	period_c;
	size_t	newline_c;
	size_t	i;

	i = 0;
	pound_c = 0;
	period_c = 0;
	newline_c = 0;
	while (buffer[i])
	{
		if (buffer[i] == '#')
			++pound_c;
		else if (buffer[i] == '.')
			++period_c;
		else if (buffer[i] == '\n' && (i % 5 == 4 || i == 20))
			++newline_c;
		else
			ft_exit("error");
		++i;
	}
	if (!(pound_c == 4 && period_c == 12 && (newline_c == 4 || newline_c == 5)))
		ft_exit("error");
	return (newline_c);
}

void	ft_check_connect(char *buffer)
{
	int	block;
	int	i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (buffer[i] == '#')
		{
			if ((i + 1) < 20 && buffer[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && buffer[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && buffer[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && buffer[i - 5] == '#')
				block++;
		}
		i++;
	}
	if (!(block == 6 || block == 8))
		ft_exit("error");
}
