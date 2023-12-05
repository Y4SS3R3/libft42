/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:04:23 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/26 00:20:05 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;

	result = NULL;
	if ((count * size) > SIZE_T_MAX)
		return (NULL);
	result = malloc(count * size);
	if (result == NULL)
		return (NULL);
	return (ft_memset(result, 0, count * size));
}
int main ()
{
	char *p = (char *)calloc(184467440737095,18446744073709551615);
	char *p1 = (char *)ft_calloc(184467440737095,18446744073709551615);
}
