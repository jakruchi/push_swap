/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 18:20:16 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/24 00:13:11 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_b(t_list *least_move, t_list **b, t_stats *stats)
{
	t_list	*lowest_diff_node;
	int		position_in_b;

	position_in_b = 1;
	lowest_diff_node = get_lowest_dif_node(least_move, *b, &position_in_b);
	if (*(least_move->data) > *(lowest_diff_node->data))
		node_goes_above(b, 'b', position_in_b, stats->b->size);
	else
		node_goes_below(b, 'b', position_in_b, stats->b->size);
}

void	move_node(t_list *least_move, t_list **a, t_list **b, t_stats *stats)
{
	int		nodes_position;
	t_list	*a_copy;

	a_copy = *a;
	nodes_position = 1;
	while (a_copy)
	{
		if (*(least_move->data) == *(a_copy->data))
			break ;
		a_copy = a_copy->next;
		nodes_position++;
	}
	if (((stats->a->size / 2) + 1) >= nodes_position)
	{
		while (nodes_position-- > 1)
			rotate(a, 'a');
	}
	else
	{
		while (nodes_position++ <= stats->a->size)
			reverse_rotate(a, 'a');
	}
	push(a, b, 'b');
}

void	move_to_pos(t_list *least_move, t_list **a, t_list **b, t_stats *stats)
{
	prepare_b(least_move, b, stats);
	move_node(least_move, a, b, stats);
}

void	prepare_a(t_list **a, t_list **b, t_stats *stats)
{
	t_list	*lowest_diff_node;
	int		position_in_a;

	position_in_a = 1;
	lowest_diff_node = get_lowest_dif_node(*b, *a, &position_in_a);
	if (*((*b)->data) < *(lowest_diff_node->data))
		node_goes_above(a, 'a', position_in_a, stats->a->size);
	else
		node_goes_below(a, 'a', position_in_a, stats->a->size);
}

void	final_rotate(t_list **lst, char letter, int extreme, int size_of_stack)
{
	int	position_of_extreme;

	position_of_extreme = find_position_of(extreme, *lst);
	if (position_of_extreme > (size_of_stack / 2))
	{
		while (extreme != *((*lst)->data))
			reverse_rotate(lst, letter);
	}
	else
	{
		while (extreme != *((*lst)->data))
			rotate(lst, letter);
	}
}
