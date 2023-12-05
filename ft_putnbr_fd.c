/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:34:44 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/14 21:17:30 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		ft_putchar_fd('-', fd);
		if (num == -2147483648)
		{
			ft_putchar_fd('2', fd);
			ft_putnbr_fd(147483648, fd);
		}
		else
		{
			num = -num;
			ft_putnbr_fd(num, fd);
		}
	}
	else if (num >= 0 && num <= 9)
		ft_putchar_fd(num + 48, fd);
	else
	{
		ft_putnbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10) + 48, fd);
	}
}
