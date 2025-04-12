/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_try.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:00:06 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/06 18:29:47 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*find_lowest_number1(t_list *list, int *lowest)
{

	if (list == NULL)
		return (NULL);
	lowest = list->content;
	if (list->next)
		list = list->next;
	while (list)
	{
		if (*lowest > *(int *)list->content)
			lowest = list->content;
		list = list->next;
	}
	return (lowest);
}

void	first_try(t_list *list_A, t_list *list_B)
{
	int	*lowest;

	while (!is_sorted(list_A) || !is_reversed_sorted(list_B))
	{
		lowest = NULL;
		lowest = find_lowest_number1(list_A, lowest);
		if (lowest == NULL)
		{
			push_a_all(&list_A, &list_B);
			break;
		}
		while (*(int *)list_A->content != *lowest)
		{
			rotate(&list_A, 'a');
		}
		push(&list_A, &list_B, 'b');
	}
	while (list_B)
		push(&list_B, &list_A, 'a');
}
