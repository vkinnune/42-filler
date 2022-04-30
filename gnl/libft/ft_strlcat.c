/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:47:40 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 17:36:00 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	dlen;

	dlen = &dest[ft_strnlen(dest, n)] - dest;
	if (dlen < n)
		ft_strncat(dest, src, n - dlen - 1);
	return (dlen + (&src[ft_strlen(src)] - src));
}
