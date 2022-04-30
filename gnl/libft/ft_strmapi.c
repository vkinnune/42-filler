/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:49:21 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 17:53:34 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	void	*temp;
	char	*str;
	size_t	size;

	size = ft_strlen((char *)s);
	i = 0;
	if (!f)
		return (0);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	temp = str;
	while (*s)
		*str++ = (f)(i++, *s++);
	*str = 0;
	return (temp);
}
