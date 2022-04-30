/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:35:08 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/11 17:15:25 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;

	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (*haystack == *needle && ft_strlen(needle) <= len)
			if (ft_strncmp(haystack, needle, nlen) == 0)
				return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
