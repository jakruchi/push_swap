/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:33:30 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/23 23:21:19 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete(int *content)
{
	free(content);
}

void	ft_lstclear(t_list **lst, void (*del)(int *))
{
	t_list	*next_node;

	while (*lst != NULL)
	{
		next_node = (*lst)->next;
		del((*lst)->data);
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}

void	free_wrong_input(void *number, t_list *list)
{
	free(number);
	ft_lstclear(&list, &delete);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_everything(t_list **a, t_list **b, t_stats *stats)
{
	ft_lstclear(a, &delete);
	ft_lstclear(b, &delete);
	free(stats->a);
	free(stats->b);
	free(stats);
}
