/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:47:32 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/19 16:26:46 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "old_push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	node = *lst;
	while (node->next != NULL)
		node = node->next;
	node->next = new;
}

void ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

void	delete(void *content)
{
	free(content);
}

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next_node;

	while (*lst != NULL)
	{
		next_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
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
			if (*(int *)lst->content > *(int *)lst->next->content)
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int	is_reversed_sorted(t_list *lst)
{
	if (lst == NULL)
		return (1);
	while (lst)
	{

		if (lst->next)
		{
			if (*(int *)lst->content < *(int *)lst->next->content)
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

void	print_list(void *content)
{
	printf("%d\n", *(int *)content);
}

void	add_5(void *content)
{
	*(int *)content += 5;
}

void	multiply_2(void *content)
{
	*(int *)content *= 2;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	t_list	*previous_node;

	new_lst = NULL;
	previous_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (previous_node != NULL)
			previous_node->next = new_node;
		else
			new_lst = new_node;
		previous_node = new_node;
		lst = lst->next;
	}
	return (new_lst);
}

void	*add_30(void *content)
{
	int	*new_content;

	new_content = (int *)malloc(sizeof(int));
	if (new_content == NULL)
		return (NULL);
	*new_content = *(int *)content + 30;
	return ((void *)new_content);
}

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	return (result * sign);
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
				printf("%6d\n", *(int *)A->content);
				A = A->next;
				size_A--;
			}
		}
		else
		{
			while (size_B != size_A)
			{
				printf("       %6d\n", *(int *)B->content);
				B = B->next;
				size_B--;
			}
		}
	}
	// printf("bigger one starts with: %d\n", *(int *)bigger_one->content);
	while (size_A > 0)
	{
		printf("%6d %6d\n", *(int *)A->content, *(int *)B->content);
		A = A->next;
		B = B->next;
		size_A--;
	}
	printf("%6c %6c\n", 'a', 'b');
}

void	swap(t_list **list, char c)
{
	int	temp;

	if (list == NULL)
		return;
	if (*list == NULL)
		return;
	if ((*list)->next == NULL)
		return;
	temp = *(int *)(*list)->content;
	*(int *)(*list)->content = *(int *)(*list)->next->content;
	*(int *)(*list)->next->content = temp;
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

int	*find_lowest_number(t_list *list, int *lowest)
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

int	*find_highest_number(t_list *list, int *highest)
{

	if (list == NULL)
		return (NULL);
	highest = list->content;
	if (list->next)
		list = list->next;
	while (list)
	{
		if (*highest < *(int *)list->content)
			highest = list->content;
		list = list->next;
	}
	return (highest);
}

void	push_a_all(t_list **list_A, t_list **list_B)
{
	while (*list_B)
	{
		push(list_B, list_A, 'a');
	}
}

int	*find_lowest(t_list *A, t_list *B, int *num_ptr)
{
	t_list	*last;

	if (A)
		num_ptr = (int *)A->content;
	else
		num_ptr = (int *)B->content;
	if (*num_ptr > *(int *)A->content)
		num_ptr = (int *)A->content;
	if (B)
	{
		if (*num_ptr > *(int *)B->content)
		num_ptr = (int *)B->content;
	}
	if (A->next)
	{
		if (*num_ptr > *(int *)A->next->content)
			num_ptr = (int *)A->next->content;
	}
	if (B->next)
	{
		if (*num_ptr > *(int *)B->next->content)
			num_ptr = (int *)B->next->content;
	}
	last = ft_lstlast(A);
	if (last)
	{
		if (*num_ptr > *(int *)last->content)
			num_ptr = (int *)last->content;
	}
	last = ft_lstlast(B);
	if (last)
	{
		if (*num_ptr > *(int *)last->content)
			num_ptr = (int *)last->content;
	}
	return (num_ptr);
}

int	*find_highest(t_list *A, t_list *B, int *num_ptr)
{
	t_list	*last;

	if (A)
		num_ptr = (int *)A->content;
	else
		num_ptr = (int *)B->content;
	if (*num_ptr < *(int *)A->content)
		num_ptr = (int *)A->content;
	if (B)
	{
		if (*num_ptr < *(int *)B->content)
		num_ptr = (int *)B->content;
	}

	if (A->next)
	{
		if (*num_ptr < *(int *)A->next->content)
			num_ptr = (int *)A->next->content;
	}
	if (B->next)
	{
		printf("i run.\n");
		if (*num_ptr < *(int *)B->next->content)
			num_ptr = (int *)B->next->content;
	}

	last = ft_lstlast(A);
	if (last)
	{
		if (*num_ptr < *(int *)last->content)
			num_ptr = (int *)last->content;
	}
	last = ft_lstlast(B);
	if (last)
	{
		if (*num_ptr < *(int *)last->content)
			num_ptr = (int *)last->content;
	}
	return (num_ptr);
}

int	find_possition(t_list *list, int *lowest)
{
	int	count;

	count = 0;
	if (lowest == NULL)
		return (count);
	while (list)
	{
		count++;
		if (*lowest == *(int *)list->content)
			break;
		list = list->next;
	}
	return (count);
}

int	get_sum(t_list *list)
{
	int	sum;

	sum = 0;
	while (list)
	{
		sum += *(int *)list->content;
		list = list->next;
	}
	return (sum);
}

void	print_array(int *array, int size)
{
	int j = 0;
	while (j < size)
	{
		printf("%d ", array[j]);
		j++;
	}
}

void sort_array(int *array, int size)
{
	int	not_sorted;
	int	i;
	int	temp;

	if (array == NULL)
		return;
	not_sorted = 1;
	while (not_sorted) // dokud je zapnuty flag, ze neni hotovo
	{
		not_sorted = 0;
		i = 0;
		while (i < size - 1) // nejsem na predposlednim elementu
		{
			if (array[i] > array[i + 1]) // kdyz aktualni element je vetsi nez element[+1]
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				not_sorted = 1;
			}
			i++;
		}
	}
}

int	find_middle(int *sorted_array, int size)
{
	int	middle;

	size /= 2;
	middle = sorted_array[size];
	return (middle);
}

int	main(int argc, char **argv)
{
	t_list	*list_A;
	t_list	*list_B;
	t_list	*new_node;
	t_list	*previous_node;
	int		*number_ptr;
	int		i;
	// int		*stats_low;
	// int		*stats_high;

	list_A = NULL;
	list_B = NULL;
	new_node = NULL;
	previous_node = NULL;
	// stats_low = NULL;
	// stats_high = NULL;
	if (argc < 3)
	{
		printf("There is no numbers to sort.\n"); // check if any number is twice
		return (1);
	}
	int	array[argc];
	i = 1;
	while (i < argc)
	{
		int	temp;
		number_ptr = (int *)malloc(sizeof(int));
		if (number_ptr == NULL)
		{
			ft_lstclear(&list_A, &delete); // delete everything
			return (1);
		}
		temp = ft_atoi(argv[i]);
		*number_ptr = temp;
		array[i - 1] = temp;
		new_node = ft_lstnew(number_ptr);
		if (previous_node)
			previous_node->next = new_node;
		else
			list_A = new_node;
		previous_node = new_node;
		i++;
	}
	printf("-----------------------array-----------------------\n");
	print_array(array, argc - 1);
	printf("\n-----------------------sorted-----------------------\n");
	sort_array(array, argc - 1);
	print_array(array, argc - 1);
	int	middle_number = find_middle(array, argc - 1);
	printf("\nmiddle number: %d\n", middle_number);
	printf("size: %d\n", argc - 1);
	printf("-----------------------init-----------------------\n");
	print_both_lists(list_A, list_B);
	// printf("-----------------------stats-----------------------\n");
	// stats_low = find_lowest_number(list_A, stats_low);
	// stats_high = find_highest_number(list_A, stats_high);
	// printf("lowest: %d, highest: %d\n", *stats_low, *stats_high);
	// printf("-----------------------prep-----------------------\n");
	// push(&list_A, &list_B, 'b');
	// push(&list_A, &list_B, 'b');
	// push(&list_A, &list_B, 'b');
	// push(&list_A, &list_B, 'b');
	// push(&list_A, &list_B, 'b');
	// push(&list_A, &list_B, 'b');
	// // push(&list_A, &list_B, 'b');
	printf("-----------------------start-----------------------\n");
	third_try(&list_A, &list_B, middle_number, argc - 1);

	// first_try(list_A, list_B); // 144 ops
	// second_try(&list_A, &list_B); // 84 ops
	printf("-----------------------done-----------------------\n");
	print_both_lists(list_A, list_B);
	// printf("i run.\n");
	ft_lstclear(&list_A, &delete);
	ft_lstclear(&list_B, &delete);
	return (0);
}

	// first_try(list_A, list_B);
	// second_try(&list_A, &list_B);

	// printf("-----------------------while-----------------------\n");
	// while (list_B)
	// 	push(&list_B, &list_A, 'a');
	// print_both_lists(list_A, list_B);
// ft_lstiter(list_A, &print_list);
	// printf("%s", is_sorted(list_A));
	// list_B = ft_lstmap(list_A, &add_30, &delete);
	// t_list	*second_node = list_B->next;
	// ft_lstdelone(list_B, &delete);
	// list_B = second_node;
	// second_node = list_B->next;
	// ft_lstdelone(list_B, &delete);
	// list_B = second_node;
	// // ft_lstiter(list_B, &print_list);
	// // printf("%-12d %-12d\n", a, b);
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// swap(&list_B, 'b');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// swap_ss(&list_A, &list_B, 's');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// swap(&list_A, 'a');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// push(&list_A, &list_B, 'b');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// push(&list_B, &list_A, 'a');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// push(&list_B, &list_A, 'a');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// push(&list_B, &list_A, 'a');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// push(&list_A, &list_B, 'b');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// push(&list_A, &list_B, 'b');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// rotate(&list_A, 'a');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// rotate(&list_B, 'b');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// rotate_rr(&list_A, &list_B, 'r');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// reverse_rotate(&list_A, 'a');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// reverse_rotate(&list_B, 'b');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);
	// printf("-----------------------------------------------\n");
	// reverse_rotate_rr(&list_A, &list_B, 'r');
	// printf("-----------------------------------------------\n");
	// print_both_lists(list_A, list_B);

