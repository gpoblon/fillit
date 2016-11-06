/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 11:46:08 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/05 14:54:39 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_grid_valid(char *str)
{
	size_t	pound_c;
	size_t	period_c;
	size_t	newline_c;
	size_t	i;

	i = 0;
	pound_c = 0;
	period_c = 0;
	newline_c = 0;
	while (str[i])
	{
		if (str[i] == '#')
			++pound_c;
		else if (str[i] == '.')
			++period_c;
		else if (str[i] == '\n' && (i == 4 || i == 9 || i == 14 || i == 19))
			++newline_c;
		else
			ft_exit("error");
		++i;
	}
	if (!(pound_c == 4 && period_c == 12 && newline_c == 4))
		ft_exit("error");
}

void	ft_check_buf_size(t_input *count)
{
	size_t	n;

	n = 1;
	while (count->buf_size > 20 * n + n - 1)
		n++;
	if (count->buf_size != 20 * n + n - 1)
		ft_exit("error");
}

void	ft_check_connect(char *str)
{
	int	block;
	int	i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	if (!(block == 6 || block == 8))
		ft_exit("error");
}
