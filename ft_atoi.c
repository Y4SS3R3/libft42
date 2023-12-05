/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:37:39 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/25 15:25:17 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(unsigned long long n, long s, int dn)
{
	if (dn >= 20 && s > 0)
		return (-1);
	if (dn >= 20 && s < 0)
		return (0);
	if (n > LONG_MAX && s > 0)
		return (-1);
	if (n > LONG_MAX && s < 0)
		return (0);
	return ((int)n * s);
}
// 9223372036854775807
// 9223372036854775807
int	ft_atoi(const char *str)
{
	size_t				i;
	unsigned long long	n;
	long				s;
	int					digitn;

	i = 0;
	n = 0;
	s = 1;
	digitn = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	while (str[i] && str[i] == '0')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		digitn++;
		n = n * 10 + (str[i++] - 48);
	}
	return (check(n, s, digitn));
}
