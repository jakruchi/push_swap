/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_try.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:22:13 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/07 18:32:22 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	second_try(t_list **list_A, t_list **list_B)
{
	int	*lowest;
	int	lowest_possition;
	int	size_A;

	while (!is_sorted(*list_A) || !is_reversed_sorted(*list_B))
	{
		lowest = NULL;
		lowest = find_lowest_number(*list_A, lowest);
		lowest_possition = find_possition(*list_A, lowest);
		size_A = ft_lstsize(*list_A);
		if ((size_A - lowest_possition) >= (size_A / 2))
		{
			while (*(int *)(*list_A)->content != *lowest)
				rotate(list_A, 'a');
		}
		else
		{
			while (*(int *)(*list_A)->content != *lowest)
				reverse_rotate(list_A, 'a');
		}
		push(list_A, list_B, 'b');
		// print_both_lists(*list_A, *list_B);
		// printf("----------------------------------------------\n");
	}
	while (*list_B)
		push(list_B, list_A, 'a');
}
