/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:24:19 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 17:37:49 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	s[12];
	int		nmb;

	ft_bzero(s, 12);
	nmb = n;
	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n = -n;
	s[i++] = n % 10 + '0';
	n /= 10;
	while (n > 0)
	{
		s[i++] = n % 10 + '0';
		n /= 10;
	}
	if (nmb < 0)
		s[i] = '-';
	return (ft_strdup(ft_strrev(s)));
}
