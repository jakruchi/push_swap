/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:45:33 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/24 01:35:36 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **list, t_stats *stats)
{
	if (stats->a->max == *((*list)->data))
		rotate(list, 'a');
	if (stats->a->min == *(ft_lstlast(*list)->data))
		reverse_rotate(list, 'a');
	if (*((*list)->data) > *((*list)->next->data))
		swap(list, 'a');
	if (stats->a->max == *((*list)->data))
		rotate(list, 'a');
	if (is_sorted(*list) == 0)
	{
		reverse_rotate(list, 'a');
		sort3(list, stats);
	}
}

void	move_everything_to_a(t_list **a, t_list **b, t_stats *stats)
{
	t_list	*b_copy;

	// --------------BUG--------------
	// kdyz jde maximum na minimum
	// ./push_swap 2147483647 32 1 7654 983 -2147483648 | ./checker_Mac 2147483647 32 1 7654 983 -2147483648
	// cisla, co to rozbijou
	// 2094190294 -1359041040 23273935 -1091272855 1202745491 -599686855 1927501462 -1047333256 -923811976 -2120394654
	// 2147483647 32 1 7654 983 -2147483648
	if (stats->b->size > 0)
		final_rotate(b, 'b', stats->b->max, stats->b->size);
	b_copy = *b;
	while (b_copy)
	{
		b_copy = b_copy->next;
		prepare_a(a, b, stats);
		push(b, a, 'a');
		update_stats(*a, *b, stats);
	}
}

void	move_everything_to_b(t_list **a, t_list **b, t_stats *stats)
{
	int		moves_to_correct_position;
	t_list	*node_with_least_moves;
	t_list	*node_to_check;
	int		temp;

	while (stats->a->size > 3 && is_sorted(*a) == 0)
	{
		node_with_least_moves = *a;
		moves_to_correct_position = compute_moves(*a, *b, stats);
		node_to_check = (*a)->next;
		temp = 0;
		while (node_to_check)
		{
			temp = compute_moves(node_to_check, *b, stats);
			if (temp < moves_to_correct_position)
			{
				moves_to_correct_position = temp;
				node_with_least_moves = node_to_check;
			}
			node_to_check = node_to_check->next;
		}
		move_to_pos(node_with_least_moves, a, b, stats);
		update_stats(*a, *b, stats);
	}
}

void	sort_manager(t_list **a, t_list **b, t_stats *stats)
{
	if (stats->a->size > 4)
		prepare_twice_push(a, b, stats);
	else if (stats->a->size == 4)
	{
		push(a, b, 'b');
		update_stats(*a, *b, stats);
	}
	else if (stats->a->size == 2)
	{
		if (is_sorted(*a) == 0)
			swap(a, 'a');
		return ;
	}
	move_everything_to_b(a, b, stats);
	sort3(a, stats);
	move_everything_to_a(a, b, stats);
	final_rotate(a, 'a', stats->a->min, stats->a->size);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_stats	*stats;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (1);
	stack_a = init_list(argc, argv);
	stats = init_stats(stack_a);
	if (is_sorted(stack_a) == 0)
		sort_manager(&stack_a, &stack_b, stats);
	free_everything(&stack_a, &stack_b, stats);
	return (0);
}
	// if (argc < 3) // delete
	// {
	// 	// ./push_swap a, chci init list, kvuli errors
	// 	//
	// 	// wrong number format if there is something els
	// 	return (0);
	// }
	// printf("-----------------------init-----------------------\n");
	// print_both_lists(stack_a, stack_b);
	// printf("max: %d\n", stats->a->max);
	// printf("min: %d\n", stats->a->min);
	// printf("size: %d\n", stats->a->size);
	// printf("-----------------------done-----------------------\n");
	// print_both_lists(stack_a, stack_b);
// void	do3(t_list **a, t_list **b)
// {
// 	printf("do3\n");
// 	push(a, b, 'b');
// 	reverse_rotate(a, 'a');
// 	push(a, b, 'b');
// 	rotate(b, 'b');
// }
// void	do2(t_list **a, t_list **b)
// {
// 	printf("do2\n");
// 	do3(a, b);
// }
// void	do1(t_list **a, t_list **b)
// {
// 	printf("do1\n");
// 	do2(a, b);
// }
// printf("-----------------------do1-----------------------\n");
// do1(&stack_a, &stack_b);
// printf("-----------------------4 push b-----------------------\n");
// push(&stack_a, &stack_b, 'b');
// push(&stack_a, &stack_b, 'b');
// push(&stack_a, &stack_b, 'b');
// push(&stack_a, &stack_b, 'b');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------rotate a-----------------------\n");
// rotate(&stack_a, 'a');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------rotate a-----------------------\n");
// rotate(&stack_a, 'a');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------rotate a-----------------------\n");
// rotate(&stack_a, 'a');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------reverse rotate a-----------------------\n");
// reverse_rotate(&stack_a, 'a');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------reverse rotate a-----------------------\n");
// reverse_rotate(&stack_a, 'a');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------reverse rotate a-----------------------\n");
// reverse_rotate(&stack_a, 'a');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------rotate b-----------------------\n");
// rotate(&stack_b, 'b');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------rotate b-----------------------\n");
// rotate(&stack_b, 'b');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------rotate b-----------------------\n");
// rotate(&stack_b, 'b');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------reverse rotate b-----------------------\n");
// reverse_rotate(&stack_b, 'b');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------reverse rotate b-----------------------\n");
// reverse_rotate(&stack_b, 'b');
// print_both_lists(stack_a, stack_b);
// printf("-----------------------reverse rotate b-----------------------\n");
// reverse_rotate(&stack_b, 'b');
// printf(" max: a: %d, b: %d\n", stats->a->max, stats->b->max);
// printf(" min: a: %d, b: %d\n", stats->a->min, stats->b->min);
// printf("size: a: %d, b: %d\n", stats->a->size, stats->b->size);
// void	print_both_lists(t_list *A, t_list *B) // delete
// {
// 	int		size_A;
// 	int		size_B;
// 	size_A = ft_lstsize(A);
// 	size_B = ft_lstsize(B);
// 	// printf("size of A: %d\nsize of B: %d\n", size_A, size_B);
// 	if (size_A != size_B)
// 	{
// 		if (size_A > size_B)
// 		{
// 			while (size_A != size_B)
// 			{
// 				printf("%6d\n", *(int *)A->data);
// 				A = A->next;
// 				size_A--;
// 			}
// 		}
// 		else
// 		{
// 			while (size_B != size_A)
// 			{
// 				printf("       %6d\n", *(int *)B->data);
// 				B = B->next;
// 				size_B--;
// 			}
// 		}
// 	}
// 	while (size_A > 0)
// 	{
// 		printf("%6d %6d\n", *(int *)A->data, *(int *)B->data);
// 		A = A->next;
// 		B = B->next;
// 		size_A--;
// 	}
// 	printf("%6c %6c\n", 'a', 'b');
// }
// void	print_list(t_list *list) // delete
// {
// 	while (list)
// 	{
// 		printf("%d\n", *(list->data));
// 		list = list->next;
// 	}
// 	printf("list\n");
// }
