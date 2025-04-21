/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:45:33 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/21 18:38:28 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_safe_atoi(const char *str, int *error)
{
	long long int	result;
	int				sign;

	result = 0;
	sign = 1;
	*error = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if ((result * sign) > 2147483647 || ((result * sign) < -2147483648))
			return (*error = 1, 0);
		str++;
	}
	if (*str != '\0')
		*error = 1;
	return ((int)(result * sign));
}

void	print_both_lists(t_list *A, t_list *B)
{
	int		size_A;
	int		size_B;

	size_A = ft_lstsize(A);
	size_B = ft_lstsize(B);
	// printf("size of A: %d\nsize of B: %d\n", size_A, size_B);
	if (size_A != size_B)
	{
		if (size_A > size_B)
		{
			while (size_A != size_B)
			{
				printf("%6d\n", *(int *)A->data);
				A = A->next;
				size_A--;
			}
		}
		else
		{
			while (size_B != size_A)
			{
				printf("       %6d\n", *(int *)B->data);
				B = B->next;
				size_B--;
			}
		}
	}
	while (size_A > 0)
	{
		printf("%6d %6d\n", *(int *)A->data, *(int *)B->data);
		A = A->next;
		B = B->next;
		size_A--;
	}
	printf("%6c %6c\n", 'a', 'b');
}

void	print_list(t_list *list)
{
	while (list)
	{
		printf("%d\n", *(list->data));
		list = list->next;
	}
	printf("list\n");
}

int	is_unique(t_list *list, int	value)
{
	while (list)
	{
		if (*(list->data) == value)
			return (0);
		list = list->next;
	}
	return (1);
}

t_list	*init_list(int argc, char **argv)
{
	t_list	*list = NULL;
	t_list	*previous_node = NULL;
	int		*number;
	int		i;
	int		error;

	i = 1;
	while (i < argc)
	{
		number = (int *)malloc(sizeof(int));
		if (number == NULL)
		{
			ft_lstclear(&list, &delete);
			write(STDOUT_FILENO, "Malloc failed.\n", 15);
			exit(EXIT_FAILURE);
		}
		*number = ft_safe_atoi(argv[i], &error);
		if (error == 1)
		{
			free(number);
			ft_lstclear(&list, &delete);
			write(STDOUT_FILENO, "Wrong number format.\n", 21);
			exit(EXIT_FAILURE);
		}
		if (is_unique(list, *number) == 0)
		{
			free(number);
			ft_lstclear(&list, &delete);
			write(STDOUT_FILENO, "Number is not unique.\n", 22);
			exit(EXIT_FAILURE);
		}
		if (previous_node == NULL)
		{
			list = ft_lstnew(number);
			if (list == NULL)
			{
				free(number);
				write(STDOUT_FILENO, "Malloc failed.\n", 15);
				exit(EXIT_FAILURE);
			}
			previous_node = list;
		}
		else
		{
			previous_node->next = ft_lstnew(number);
			if (previous_node->next == NULL)
			{
				free(number);
				ft_lstclear(&list, &delete);
				write(STDOUT_FILENO, "Malloc failed.\n", 15);
				exit(EXIT_FAILURE);
			}
			previous_node = previous_node->next;
		}
		i++;
	}
	return (list);
}

t_stats	*init_stats(t_list *stack_a, int list_size)
{
	t_stats	*stats;
	t_stack	*stats_a;
	t_stack	*stats_b;

	stats = (t_stats *)malloc(sizeof(t_stats));
	if (stats == NULL)
	{
		ft_lstclear(&stack_a, &delete);
		write(STDOUT_FILENO, "Malloc failed.\n", 15);
		exit(EXIT_FAILURE);
	}
	stats_b = (t_stack *)malloc(sizeof(t_stack));
	if (stats_b == NULL)
	{
		free(stats);
		ft_lstclear(&stack_a, &delete);
		write(STDOUT_FILENO, "Malloc failed.\n", 15);
		exit(EXIT_FAILURE);
	}
	stats->b = stats_b;
	stats_a = (t_stack *)malloc(sizeof(t_stack));
	if (stats_a == NULL)
	{
		free(stats->b);
		free(stats);
		ft_lstclear(&stack_a, &delete);
		write(STDOUT_FILENO, "Malloc failed.\n", 15);
		exit(EXIT_FAILURE);
	}
	stats->a = stats_a;
	stats->a->max = *(stack_a->data);
	stats->a->min = *(stack_a->data);
	while (stack_a)
	{
		if (*(stack_a->data) > stats->a->max)
			stats->a->max = *(stack_a->data);
		if (*(stack_a->data) < stats->a->min)
			stats->a->min = *(stack_a->data);
		stack_a = stack_a->next;
	}
	stats->b->size = 0;
	stats->a->size = list_size;
	return (stats);
}
void	update_stats(t_list *a, t_list *b, t_stats *stats)
{
	int	size;

	if (a == NULL)
		printf("a is null.\n");
	if (a->data == NULL)
		printf("its null.\n");
	stats->a->max = *(a->data);
	stats->a->min = *(a->data);
	stats->a->size = 0;
	size = 0;
	while (a)
	{
		if (*(a->data) > stats->a->max)
			stats->a->max = *(a->data);
		if (*(a->data) < stats->a->min)
			stats->a->min = *(a->data);
		a = a->next;
		size++;
	}
	stats->a->size = size;
	if (b)
	{
		stats->b->max = *(b->data);
		stats->b->min = *(b->data);
		stats->b->size = 0;
		size = 0;
		while (b)
		{
			if (*(b->data) > stats->b->max)
				stats->b->max = *(b->data);
			if (*(b->data) < stats->b->min)
				stats->b->min = *(b->data);
			b = b->next;
			size++;
		}
		stats->b->size = size;
		printf(" max: a: %d, b: %d\n", stats->a->max, stats->b->max);
		printf(" min: a: %d, b: %d\n", stats->a->min, stats->b->min);
		printf("size: a: %d, b: %d\n", stats->a->size, stats->b->size);
	}
}

int	is_sorted(t_list *lst)
{
	if (lst == NULL)
		return (0);
	while (lst)
	{

		if (lst->next)
		{
			if (*lst->data > *lst->next->data)
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int	calculate_moves_in_a(t_list *node_to_check, t_stats *stats)
{
	static int	moves_in_stack_a;
	static int	i;

	i++;
	if (((stats->a->size / 2) + 1) >= i)
		moves_in_stack_a++;
	else if (((stats->a->size / 2) + 2) >= i && stats->a->size % 2 != 0)
		;
	else // for performance move this in front of else if
		moves_in_stack_a--;
	if (node_to_check->next == NULL)
	{
		moves_in_stack_a = 0;
		i = 0;
		return (2);
	}
	return (moves_in_stack_a);
}

int	calculate_moves_in_b(t_list *node_to_check, t_list *b, t_stats *stats)
{
	long long int	absolute_diff;
	t_list			*node_with_lowest_absolut_diff;
	int				position_in_b;
	long long int	temp; // if - int min - + int max = overflow!!!

	position_in_b = 1;
	node_with_lowest_absolut_diff = b;
	absolute_diff = *(b->data) - *(node_to_check->data);
	if (absolute_diff < 0)
		absolute_diff *= -1;
	int	i = 0;
	while (b)
	{
		temp = *(b->data) - *(node_to_check->data);
		if (temp < 0)
			temp *= -1;
		i++;
		if (temp < absolute_diff)
		{
			position_in_b = i;
			absolute_diff = temp;
			node_with_lowest_absolut_diff = b;
		}
		b = b->next;
	}
	if (*(node_to_check->data) > *(node_with_lowest_absolut_diff->data))
	{
		// node_with musi jit nahoru
		if (position_in_b < (stats->b->size / 2)) // + 1 // je v prvni pulce
			position_in_b -= 1; // pujde horem (tedy position_in_b - 1)
		else // nebo v druhe pulce
			position_in_b = stats->b->size - position_in_b + 1;// pujde spodem (size - position_in_b + 1)
	}
	else
	{
		// node_with musi jit dolu
		if (position_in_b < (stats->b->size / 2)) // - 1 // je v prvni pulce
			; // pujde horem (tedy position_in_b)
		else // nebo v druhe pulce
			position_in_b = stats->b->size - position_in_b; // pujde zpodem (size - position_in_b)
	}
	(void)node_with_lowest_absolut_diff;
	(void)stats;
	return (position_in_b);
}
// find the lowest absolute value of difference between
// node_to_check and stack be and then i know that
// the node goes right below or above the node
// with the lowest absolut value

int	calculate_moves(t_list *node_to_check, t_list *stack_b, t_stats *stats)
{
	int	result;

	result = calculate_moves_in_a(node_to_check, stats);
	result += calculate_moves_in_b(node_to_check, stack_b, stats);
	return (result);
}

void	prepare_b(t_list *node_with_least_moves, t_list **b, t_stats *stats)
{
	long long int	absolute_diff;
	t_list			*node_with_lowest_absolut_diff;
	int				position_in_b;
	long long int	temp; // if - int min - + int max = overflow!!!
	t_list			*b_copy;

	b_copy = *b;
	position_in_b = 1;
	node_with_lowest_absolut_diff = b_copy;
	absolute_diff = *(b_copy->data) - *(node_with_least_moves->data);
	if (absolute_diff < 0)
		absolute_diff *= -1;
	int	i = 0;
	// print_list(*b);
	while (b_copy)
	{
		temp = *(b_copy->data) - *(node_with_least_moves->data);
		if (temp < 0)
			temp *= -1;
		i++;
		if (temp < absolute_diff)
		{
			position_in_b = i;
			absolute_diff = temp;
			node_with_lowest_absolut_diff = b_copy;
		}
		b_copy = b_copy->next;
	}
	// print_list(*b);
	if (*(node_with_least_moves->data) > *(node_with_lowest_absolut_diff->data))
	{
		// node_with musi jit nahoru
		if (position_in_b < (stats->b->size / 2)) // + 1 // je v prvni pulce
		{
			int	j = 0;
			while (j < position_in_b - 1)
			{
				rotate(b, 'b');
				j++;
			}
		}
			// position_in_b -= 1; // pujde horem (tedy position_in_b - 1)
		else // nebo v druhe pulce
		{
			int	j = 0;
			while (j < stats->b->size - position_in_b + 1)
			{
				reverse_rotate(b, 'b');
				j++;
			}
		}
			// position_in_b = stats->b->size - position_in_b + 1;// pujde spodem (size - position_in_b + 1)
	}
	else
	{
		// node_with musi jit dolu
		if (position_in_b < (stats->b->size / 2)) // - 1 // je v prvni pulce
		{
			int	j = 0;
			while (j < position_in_b)
			{
				rotate(b, 'b');
				j++;
			}
		}
			// pujde horem (tedy position_in_b)
		else // nebo v druhe pulce
		{
			int	j = 0;
			while (j < stats->b->size - position_in_b)
			{
				reverse_rotate(b, 'b');
				j++;
			}
		}
			// position_in_b = stats->b->size - position_in_b; // pujde zpodem (size - position_in_b)
	}
}

void	move_node(t_list *node_with_least_moves, t_list **a, t_list **b, t_stats *stats)
{
	int	nodes_position;
	t_list	*a_copy;

	a_copy = *a;
	nodes_position = 1;
	while (a_copy)
	{
		if (*(node_with_least_moves->data) == *(a_copy->data))
			break;
		a_copy = a_copy->next; // sus
		nodes_position++;
	}
	if (((stats->a->size / 2) + 1) >= nodes_position)
	{
		// v prvni pulce
		while (nodes_position > 1)
		{
			rotate(a, 'a');
			nodes_position--;
		}
	}
	else
	{
		while (nodes_position <= stats->a->size)
		{
			reverse_rotate(a, 'a');
			nodes_position++;
		}
	}
	push(a, b, 'b');

}

void	move_to_position(t_list *node_with_least_moves, t_list **a, t_list **b, t_stats *stats)
{
	prepare_b(node_with_least_moves, b, stats);
	move_node(node_with_least_moves, a, b, stats);
}

void	prepare_twice_push(t_list **a, t_list **b, t_stats *stats)
{
	push(a, b, 'b');
	push(a, b, 'b');
	update_stats(*a, *b, stats);
}

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

void	prepare_a(t_list **a, t_list **b, t_stats *stats)
{
	long long int	absolute_diff;
	t_list			*a_copy;

	a_copy = *a;
	absolute_diff = *()
}

void	move_everything_to_a(t_list **a, t_list **b, t_stats *stats)
{
	t_list	*b_copy;

	b_copy = *b;
	while (b_copy)
	{
		prepare_a(a, b, stats);
		push(a, b, 'b');
		update_stats(*a, *b, stats);
		b_copy = b_copy->next;
	}
}

void	sort_algorithm(t_list **a, t_list **b, t_stats *stats)
{
	int		moves_to_correct_position;
	t_list *node_with_least_moves;
	t_list *node_to_check;
	int		temp;


	if (stats->a->size > 4)
	{
		printf("-----------------------prep-----------------------\n");
		prepare_twice_push(a, b, stats);
		print_both_lists(*a, *b);
	}
	else if (stats->a->size == 4)
	{
		printf("-----------------------prep-----------------------\n");
		push(a, b, 'b');
		update_stats(*a, *b, stats);
		print_both_lists(*a, *b);
	}
	else if (stats->a->size == 2)
	{
		if (is_sorted(*a) == 0)
		{
			swap(a, 'a');
		}
		return;
	}
	printf("-----------------------start-----------------------\n");
	while (stats->a->size > 3 && is_sorted(*a) == 0)
	{
		node_to_check = *a;
		node_with_least_moves = *a;
		moves_to_correct_position = calculate_moves(*a, *b,stats); // should return node_with_least_moves
		printf("%d takes %d moves to correct position\n", *(node_to_check->data), moves_to_correct_position);
		node_to_check = (*a)->next;
		temp = 0;
		while (node_to_check)
		{
			temp = calculate_moves(node_to_check, *b, stats);
			printf("%d takes %d moves to correct position\n", *(node_to_check->data), temp);
			if (temp < moves_to_correct_position)
			{
				moves_to_correct_position = temp;
				node_with_least_moves = node_to_check;
				(void)node_with_least_moves;
			}
			node_to_check = node_to_check->next;
		}
		move_to_position(node_with_least_moves, a, b, stats);
		print_both_lists(*a, *b);
		update_stats(*a, *b, stats);
	}
	sort3(a, stats);
	// move_everything_to_a(a, b, stats);
	// printf("i run.\n");
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_stats	*stats;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		exit(1);
	stack_a = init_list(argc, argv);
	printf("-----------------------init-----------------------\n");
	print_both_lists(stack_a, stack_b);
	stats = init_stats(stack_a, argc - 1);
	printf("max: %d\n", stats->a->max);
	printf("min: %d\n", stats->a->min);
	printf("size: %d\n", stats->a->size);
	sort_algorithm(&stack_a, &stack_b, stats);
	printf("-----------------------done-----------------------\n");
	print_both_lists(stack_a, stack_b);
	if (is_sorted(stack_a) == 1)
		printf("stack A is sorted.\n");
	ft_lstclear(&stack_a, &delete);
	ft_lstclear(&stack_b, &delete);
	free(stats->a);
	free(stats->b);
	free(stats);
	return (0);
}

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
