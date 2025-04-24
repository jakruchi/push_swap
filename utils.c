/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:17:45 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/23 18:19:17 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	node_goes_above(t_list **list, char letter, int position, int size)
{
	int	i;

	i = 0;
	if (position < (size / 2))
	{
		while (i++ < position - 1)
			rotate(list, letter);
	}
	else
	{
		while (i++ < size - position + 1)
			reverse_rotate(list, letter);
	}
}

void	node_goes_below(t_list **list, char letter, int position, int size)
{
	int	i;

	i = 0;
	if (position < (size / 2))
	{
		while (i++ < position)
			rotate(list, letter);
	}
	else
	{
		while (i++ < size - position)
			reverse_rotate(list, letter);
	}
}

void	prepare_twice_push(t_list **a, t_list **b, t_stats *stats)
{
	push(a, b, 'b');
	push(a, b, 'b');
	update_stats(*a, *b, stats);
}

int	find_position_of(int value, t_list *list)
{
	int	position;

	position = 1;
	while (*(list->data) != value)
	{
		position++;
		list = list->next;
	}
	return (position);
}
