/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:32:53 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/28 21:28:26 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	f[4350][BUFF_SIZE * 2 + 1];
	int			n;

	if (!line || fd < 0 || fd > 4349 || BUFF_SIZE < 1 || read(fd, f[fd], 0))
		return (-1);
	*line = 0;
	if (ft_strchr(f[fd], '\n'))
		*line = ft_strdup(f[fd]);
	while (!*line || !(ft_strchr(*line, '\n')))
	{
		if ((read(fd, &f[fd][ft_strlen(f[fd])], BUFF_SIZE) < 1) && !*f[fd])
			return ((read(fd, f[fd], 0)) + (*line != 0));
		ft_strcat(*line = ft_dumbrealloc(*line, ft_strlen(f[fd])
				+ ft_strlen(*line) + 1, ft_strlen(*line) + 1), f[fd]);
		ft_bzero(f[fd], BUFF_SIZE * 2 + 1);
	}
	ft_strncpy(f[fd], (ft_strchr(*line, '\n') + 1), BUFF_SIZE);
	n = ft_strchr(*line, '\n') - *line;
	*line = ft_dumbrealloc(*line, n + 1, n + 1);
	*(ft_strchr(*line, '\n')) = 0;
	return (1);
}
