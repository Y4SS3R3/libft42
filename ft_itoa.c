/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 20:26:53 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/18 18:27:36 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbrlen(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static char	*allocate(int len)
{
	char	*allocated;

	allocated = NULL;
	allocated = (char *)malloc(len + 1);
	if (allocated == NULL)
		return (NULL);
	return (allocated);
}

char	*ft_itoa(int n)
{
	int		len;
	long	ntmp;
	char	*result;
	int		i;

	ntmp = n;
	i = 0;
	len = nbrlen(ntmp);
	result = allocate(len);
	if (result == NULL)
		return (NULL);
	if (ntmp < 0)
	{
		result[i] = '-';
		i++;
		ntmp = -ntmp;
	}
	result[len--] = 0;
	while (len >= i)
	{
		result[len--] = (ntmp % 10) + 48;
		ntmp /= 10;
	}
	return (result);
}
