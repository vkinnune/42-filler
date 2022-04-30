/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:33:37 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 17:35:45 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	size;

	size = ft_strnlen((char *)src, n);
	if (ft_strlen(src) < n)
		ft_memset (dest + size, '\0', n - size);
	return (ft_memcpy(dest, src, size));
}
