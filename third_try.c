/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   third_try.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 21:23:36 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/07 21:54:31 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	third_try(t_list **A, t_list **B, int middle, int size)
{
	int	*lowest;
	int	lowest_possition;
	int	size_A;

	int j = 0;
	while (j < 100)
	{
		lowest = NULL;
		lowest = find_lowest_number(*A, lowest);
		lowest_possition = find_possition(*A, lowest);
		size_A = ft_lstsize(*A);
		if ((size_A - lowest_possition) >= (size_A / 2))
		{
			while (*(int *)(*A)->content != *lowest)
			{
				if (*(int *)(*A)->content > middle)
					rotate(A, 'a');
				else
					push(A, B, 'b');
				printf("----------------------------------------------\n");
				print_both_lists(*A, *B);
				sleep (2);
			}
		}
		else
		{
			while (*(int *)(*A)->content != *lowest)
			{
				reverse_rotate(A, 'a');
				if (*(int *)(*A)->content < middle)
					push(A, B, 'b');
				printf("----------------------------------------------\n");
				print_both_lists(*A, *B);
				sleep (2);
			}
		}
		printf("----------------------------------------------\n");
		print_both_lists(*A, *B);
	}
	(void)size;
}
