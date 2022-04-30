/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:57:34 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 17:37:56 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*res;
	char		*tmp_res;
	const char	*tmp_s;

	if (!s)
		return (0);
	tmp_s = s;
	tmp_s += ft_strlen(s) - 1;
	while (ft_iswhitespace(*s))
		if (!s++ || *s == 0)
			return (ft_strnew(1));
	while (ft_iswhitespace(*tmp_s))
		tmp_s--;
	res = (char *)malloc((tmp_s - s) + 2);
	if (!res)
		return (0);
	tmp_res = res;
	while (s - 1 != tmp_s)
		*res++ = *s++;
	*res = 0;
	return (tmp_res);
}
