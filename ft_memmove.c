/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:07:23 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/02 12:08:15 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmpd;
	unsigned char	*tmps;

	tmpd = (unsigned char *)dst;
	tmps = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
		while (len--)
			tmpd[len] = tmps[len];
	return (dst);
}
