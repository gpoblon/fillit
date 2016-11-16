/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:18:49 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/16 15:44:07 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	ft_get_tetri(char *filename, t_tetri **tetri,
		size_t tdesc_count)
{
	int		fd;
	char	buffer[BUFF_SIZE + 1];
	size_t	last_newline;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit("error");
	while (ft_read_fd(fd, buffer))
	{
		last_newline = ft_check_grid_valid(buffer);
		ft_check_connect(buffer);
		ft_set_tetri(tetri, buffer, tdesc_count);
		tdesc_count++;
	}
	if (tdesc_count < 1 || tdesc_count > 26 || last_newline == 5)
		ft_exit("error");
	if (close(fd) == -1)
		ft_exit("error");
	return (tdesc_count);
}

int		ft_read_fd(int fd, char *buffer)
{
	int		count;

	count = read(fd, buffer, BUFF_SIZE);
	buffer[count] = '\0';
	return (count);
}
