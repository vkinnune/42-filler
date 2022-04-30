/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkinnune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 21:59:42 by vkinnune          #+#    #+#             */
/*   Updated: 2021/12/09 17:39:05 by vkinnune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	s[12];
	int		nmb;

	ft_bzero(s, 12);
	nmb = n;
	i = 0;
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
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
	ft_putstr_fd(ft_strrev(s), fd);
}
