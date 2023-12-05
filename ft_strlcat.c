/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:42:16 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/15 15:35:30 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	dlen;
	size_t	i;

	i = 0;
	slen = ft_strlen(src);
	if (dst == NULL && dstsize == 0)
		return (slen);
	while (dst[i])
		i++;
	dlen = i;
	if (dstsize <= dlen)
		return (dstsize + slen);
	if (dlen + slen < dstsize)
		ft_memcpy(&dst[i], src, slen + 1);
	else
	{
		ft_memcpy(&dst[i], src, dstsize - dlen - 1);
		dst[dstsize - 1] = 0;
	}
	return (dlen + slen);
}
