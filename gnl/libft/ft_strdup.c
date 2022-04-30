/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:31:46 by vkinnune          #+#    #+#             */
/*   Updated: 2021/11/10 13:56:05 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	void	*ns;
	size_t	len;

	len = ft_strlen((void *)s) + 1;
	ns = (char *)malloc(len);
	if (ns == 0)
		return (0);
	return ((char *)ft_memcpy(ns, s, len));
}
