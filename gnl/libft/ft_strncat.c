/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:32:55 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 16:43:10 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*addnull;

	addnull = ft_mempcpy(dest + ft_strlen(dest), src, ft_strnlen(src, n));
	*addnull = 0;
	return (dest);
}
