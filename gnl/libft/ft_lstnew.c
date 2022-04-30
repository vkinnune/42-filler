/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:32:16 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/13 13:38:53 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p_new;

	p_new = ft_memalloc(sizeof(t_list));
	if (!p_new)
		return (0);
	p_new->content = ft_memalloc(content_size);
	if (!p_new->content)
		return (0);
	if (!content)
	{
		p_new->content = 0;
		p_new->content_size = 0;
	}
	else
	{
		ft_memcpy(p_new->content, content, content_size);
		p_new->content_size = content_size;
	}
	return (p_new);
}
