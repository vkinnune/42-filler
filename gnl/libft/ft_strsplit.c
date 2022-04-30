/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:56:32 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/11 17:05:52 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**p_arr;
	char	*temp_ptr;
	int		i_arr[2];

	temp_ptr = 0;
	ft_memset(i_arr, 0, sizeof(i_arr));
	while (ft_strtok(s, c, &temp_ptr))
	{	
		i_arr[0] = i_arr[0] + ft_strlen(temp_ptr);
		i_arr[1]++;
	}
	p_arr = (char **)malloc(((i_arr[1]) + 1 * 8) + (i_arr[0] + i_arr[1] - 1));
	if (!p_arr)
		return (0);
	if (i_arr[0] && i_arr[1])
		*p_arr = (char *)&p_arr[i_arr[1] + 1];
	ft_memset(i_arr, 0, sizeof(i_arr));
	while (ft_strtok(s, c, &temp_ptr) && *p_arr && p_arr)
	{
		p_arr[i_arr[1]++] = ft_strcpy(&p_arr[0][i_arr[0]], temp_ptr);
		i_arr[0] = i_arr[0] + ft_strlen(temp_ptr) + 1;
	}
	p_arr[i_arr[1]] = 0;
	return (p_arr);
}
