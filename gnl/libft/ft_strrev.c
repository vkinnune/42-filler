/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:53:06 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/02 21:53:43 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		size;
	char	c;

	size = ft_strlen(str);
	i = 0;
	while (i < (size - 1 / 2))
	{
		c = str[i];
		str[i] = str[--size];
		str[size] = c;
		i++;
	}
	return (str);
}
