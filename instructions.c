/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 10:58:42 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/20 11:17:17 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **list, char c)
{
	int	temp;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	temp = *(*list)->data;
	*(*list)->data = *(*list)->next->data;
	*(*list)->next->data = temp;
	if (c == 'a' || c == 'b')
		printf("s%c\n", c);
}

void	swap_ss(t_list **A, t_list **B, char c)
{
	if (A == NULL || B == NULL)
		return;
	if (*A == NULL || *B == NULL)
		return;
	if ((*A)->next == NULL || (*B)->next == NULL)
		return;
	swap(A, c);
	swap(B, c);
	printf("s%c\n", c);
}

void	push(t_list **from, t_list **in, char c)
{
	t_list	*temp;

	if (from == NULL)
		return;
	if (*from == NULL)
		return;
	if (in == NULL)
		return;
	temp = (*from)->next;
	ft_lstadd_front(in, *from);
	*from = temp;
	printf("p%c\n", c);
}

void	rotate(t_list **list, char c)
{
	t_list	*second_node;
	t_list	*last_node;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	second_node = (*list)->next;
	last_node = ft_lstlast(*list);
	(*list)->next = NULL;
	last_node->next = *list;
	*list = second_node;
	if (c == 'a' || c == 'b')
		printf("r%c\n", c);
}

void	rotate_rr(t_list **list_A, t_list **list_B, char c)
{
	rotate(list_A, c);
	rotate(list_B, c);
	printf("r%c\n", c);
}

void	reverse_rotate(t_list **list, char c)
{
	t_list	*last_node;
	t_list	*second_to_last_node;
	int		size;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	last_node = ft_lstlast(*list);
	size = ft_lstsize(*list);
	second_to_last_node = *list;
	while (size > 2)
	{
		second_to_last_node = second_to_last_node->next;
		size--;
	}
	last_node->next = *list;
	*list = last_node;
	second_to_last_node->next = NULL;
	if (c == 'a' || c == 'b')
		printf("rr%c\n", c);
}

void	reverse_rotate_rr(t_list **list_A, t_list **list_B, char c)
{
	reverse_rotate(list_A, c);
	reverse_rotate(list_B, c);
	printf("rr%c\n", c);
}
