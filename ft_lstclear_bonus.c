/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymassiou <ymassiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:11:54 by ymassiou          #+#    #+#             */
/*   Updated: 2023/11/19 15:40:17 by ymassiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	head = *lst;
	tmp = *lst;
	while (head != NULL)
	{
		head = head->next;
		del(tmp->content);
		free(tmp);
		tmp = head;
	}
	*lst = NULL;
}
