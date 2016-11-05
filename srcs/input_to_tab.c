/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpoblon <gpoblon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:18:49 by gpoblon           #+#    #+#             */
/*   Updated: 2016/11/05 14:40:29 by gpoblon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_input_to_str(char *filename, t_input *count)
{
	int		fd;
	char	buffer;

	count->buf_size = 0;
	count->tdesc_count = 0;
	count->buf_count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit("error");
	while (read(fd, &buffer, 1))
	{
		if (!(buffer == '.' || buffer == '#' || buffer == '\n'))
			ft_exit("error");
		if (buffer == '\n')
			count->tdesc_count++;
		count->buf_size++;
	}
	if (close(fd) == -1)
		ft_exit("error");
	count->tdesc_count = (count->tdesc_count / 5) + 0.5;
	if (count->buf_size < 20 || count->buf_size > 545)
		ft_exit("error");
	ft_check_buf_size(count);
	return (ft_get_str(filename, count));
}

char	*ft_get_str(char *filename, t_input *count)
{
	int		fd;
	char	buffer;
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)malloc(sizeof(char) * count->buf_size + 1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_exit("error");
	while (read(fd, &buffer, 1))
	{
		str[i] = buffer;
		i++;
	}
	if (close(fd) == -1)
		ft_exit("error");
	str[i] = '\0';
	return (str);
}
