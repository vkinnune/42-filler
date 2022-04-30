/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:32:07 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/30 13:32:10 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_dumbrealloc(void *ptr, size_t size, size_t oldsize)
{
	char	*tmp_ptr;

	if (!size)
		return (0);
	if (!ptr)
	{
		ptr = ft_memalloc(size);
		return (ptr);
	}
	tmp_ptr = ft_memalloc(size);
	ft_memcpy(tmp_ptr, ptr, oldsize);
	free(ptr);
	ptr = tmp_ptr;
	return (ptr);
}
