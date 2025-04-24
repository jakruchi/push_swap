/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:37:05 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/23 17:38:55 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*init_number(t_list *list, char *input)
{
	int	*number;
	int	error;

	number = (int *)malloc(sizeof(int));
	if (number == NULL)
		free_wrong_input(NULL, list);
	*number = ft_safe_atoi(input, &error);
	if (error == 1)
		free_wrong_input(number, list);
	if (is_unique(list, *number) == 0)
		free_wrong_input(number, list);
	return (number);
}

t_list	*init_node(int *number, t_list *list)
{
	t_list	*node;

	node = ft_lstnew(number);
	if (node == NULL)
		free_wrong_input(number, list);
	return (node);
}

t_list	*init_list(int argc, char **argv)
{
	t_list	*list;
	t_list	*previous_node;
	int		*number;
	int		i;

	list = NULL;
	previous_node = NULL;
	i = 1;
	while (i < argc)
	{
		number = init_number(list, argv[i++]);
		if (previous_node == NULL)
		{
			list = init_node(number, list);
			previous_node = list;
		}
		else
		{
			previous_node->next = init_node(number, list);
			previous_node = previous_node->next;
		}
	}
	return (list);
}
