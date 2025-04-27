/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakruchi <jakruchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:05:05 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/27 14:51:05 by jakruchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compute_moves_in_a(t_list *node_to_check, t_stats *stats)
{
	static int	moves_in_stack_a;
	static int	i;

	i++;
	if (((stats->a->size / 2) + 1) >= i)
		moves_in_stack_a++;
	else if (((stats->a->size / 2) + 2) >= i && stats->a->size % 2 != 0)
		;
	else
		moves_in_stack_a--;
	if (node_to_check->next == NULL)
	{
		moves_in_stack_a = 0;
		i = 0;
		return (2);
	}
	return (moves_in_stack_a);
}

t_list	*get_lowest_dif_node(t_list *node_to_check, t_list *lst, int *position)
{
	long long int	absolute_diff;
	t_list			*lowest_diff_node;
	long long int	temp;
	int				i;

	lowest_diff_node = lst;
	absolute_diff = (long long)*(lst->data) - (long long)*(node_to_check->data);
	if (absolute_diff < 0)
		absolute_diff *= -1;
	i = 0;
	while (lst)
	{
		temp = (long long)*(lst->data) - (long long)*(node_to_check->data);
		if (temp < 0)
			temp *= -1;
		i++;
		if (temp < absolute_diff)
		{
			*position = i;
			absolute_diff = temp;
			lowest_diff_node = lst;
		}
		lst = lst->next;
	}
	return (lowest_diff_node);
}

int	compute_moves_in_b(t_list *node_to_check, t_list *b, t_stats *stats)
{
	t_list			*lowest_diff_node;
	int				position_in_b;

	position_in_b = 1;
	lowest_diff_node = get_lowest_dif_node(node_to_check, b, &position_in_b);
	if (*(node_to_check->data) > *(lowest_diff_node->data))
	{
		if (position_in_b < (stats->b->size / 2))
			position_in_b -= 1;
		else
			position_in_b = stats->b->size - position_in_b + 1;
	}
	else
	{
		if (position_in_b > (stats->b->size / 2))
			position_in_b = stats->b->size - position_in_b;
	}
	return (position_in_b);
}

int	compute_moves(t_list *node_to_check, t_list *stack_b, t_stats *stats)
{
	int	result;

	result = compute_moves_in_a(node_to_check, stats);
	result += compute_moves_in_b(node_to_check, stack_b, stats);
	return (result);
}
