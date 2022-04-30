/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:45:59 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/02 21:47:13 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
	if (!new)
		return (0);
	ft_strcpy(new, s1);
	new = ft_strcat(new, s2);
	return (new);
}
