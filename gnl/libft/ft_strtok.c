/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:00:47 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 19:57:56 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtok(const char *s, char c, char **line)
{
	static char	*buf;
	char		*tmp_s;

	if (!*line)
	{
		buf = ft_strdup(s);
		tmp_s = buf;
	}
	while (*buf == c)
		buf++;
	if (!buf || !*buf)
	{
		ft_bzero(line, sizeof(line));
		free(tmp_s);
		return (0);
	}
	*line = buf;
	while (*buf && *buf != c)
		buf++;
	if (*buf)
	{
		*buf = 0;
		buf++;
	}
	return (*line);
}
