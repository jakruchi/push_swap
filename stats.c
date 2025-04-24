/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:39:45 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/23 17:40:12 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_substats(t_list *list, t_stack *sub_stats)
{
	int	size;

	sub_stats->max = *(list->data);
	sub_stats->min = *(list->data);
	sub_stats->size = 0;
	size = 0;
	while (list)
	{
		if (*(list->data) > sub_stats->max)
			sub_stats->max = *(list->data);
		if (*(list->data) < sub_stats->min)
			sub_stats->min = *(list->data);
		list = list->next;
		size++;
	}
	sub_stats->size = size;
}

void	update_stats(t_list *a, t_list *b, t_stats *stats)
{
	update_substats(a, stats->a);
	if (b)
		update_substats(b, stats->b);
}

t_stats	*init_stats(t_list *stack_a)
{
	t_stats	*stats;

	stats = (t_stats *)malloc(sizeof(t_stats));
	if (stats == NULL)
		free_wrong_input(NULL, stack_a);
	stats->b = (t_stack *)malloc(sizeof(t_stack));
	if (stats->b == NULL)
		free_wrong_input(stats, stack_a);
	stats->a = (t_stack *)malloc(sizeof(t_stack));
	if (stats->a == NULL)
	{
		free(stats->b);
		free_wrong_input(stats, stack_a);
	}
	update_substats(stack_a, stats->a);
	stats->b->size = 0;
	return (stats);
}
