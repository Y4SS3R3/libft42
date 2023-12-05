/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:37:20 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/22 13:45:22 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(char needle, const char *haystack)
{
	size_t	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (1);
		i++;
	}
	return (0);
}

static char	*generate(size_t len, const char *src)
{
	char	*result;
	size_t	i;

	i = 0;
	result = NULL;
	result = (char *)malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = src[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	result = NULL;
	j = ft_strlen(s1) - 1;
	while (check(s1[i], set))
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	while (check(s1[j], set))
		j--;
	result = generate(j - i + 1, &s1[i]);
	if (result == NULL)
		return (NULL);
	return (result);
}
