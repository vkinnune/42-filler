/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:27:29 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/02 21:38:01 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src < dest)
		while (++i <= n)
			((char *)dest)[n - i] = ((char *)src)[n - i];
	else if (src > dest)
		ft_mempcpy(dest, src, n);
	return (dest);
}
