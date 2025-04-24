/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:12:36 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/23 17:34:16 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->data = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
// 	t_list	*node;

// 	node = *lst;
// 	while (node->next != NULL)
// 		node = node->next;
// 	node->next = new;
// }

// void ft_lstdelone(t_list *lst, void (*del)(void*))
// {
// 	del(lst->data);
// 	free(lst);
// }
// void	ft_lstiter(t_list *lst, void (*f)(int *))
// {
// 	while (lst)
// 	{
// 		f(lst->data);
// 		lst = lst->next;
// 	}
// }
