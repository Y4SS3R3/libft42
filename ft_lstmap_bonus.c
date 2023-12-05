/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:32:40 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/22 14:08:27 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*result_head;

	if (!lst || !f || !del)
		return (NULL);
	result = NULL;
	result_head = NULL;
	while (lst != NULL)
	{
		result = ft_lstnew(NULL);
		if (result == NULL)
		{
			ft_lstclear(&result_head, del);
			return (NULL);
		}
		result->content = f(lst->content);
		ft_lstadd_back(&result_head, result);
		lst = lst->next;
	}
	return (result_head);
}
