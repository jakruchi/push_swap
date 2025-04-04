/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:47:32 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/04 13:59:04 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h> // malloc, free
#include <stdio.h> // printf

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

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

static int	ft_atoi(const char *nptr)
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

int	main(int argc, char **argv)
{
	int	*temp;
	int	i;

	if (argc < 3)
		printf("There is no numbers to sort.");
	i = 0;
	while (i < argc)
	{
		temp = (int *)malloc(sizeof(int));
		if (temp = NULL)
		{
			ft_lstclear();
			return (1);
		}
		ft_lstnew()
		i++;
	}
	return (0);
}
