/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:45:37 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/20 11:13:56 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>	// malloc, free
#include <unistd.h>	// write
#include <stdio.h>	// printf

typedef struct		s_list
{
	int				*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_stack
{
	int				min;
	int				max;
	int				size;
}					t_stack;

typedef struct		s_stats
{
	t_stack			*a;
	t_stack			*b;
}					t_stats;

// instructions.c
void	swap(t_list **list, char c);
void	swap_ss(t_list **A, t_list **B, char c);
void	push(t_list **from, t_list **in, char c);
void	rotate(t_list **list, char c);
void	rotate_rr(t_list **list_A, t_list **list_B, char c);
void	reverse_rotate(t_list **list, char c);
void	reverse_rotate_rr(t_list **list_A, t_list **list_B, char c);

// list_functions.c
t_list	*ft_lstnew(int *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void	delete(int *content);
void ft_lstclear(t_list **lst, void (*del)(int *));
void	ft_lstiter(t_list *lst, void (*f)(int *));

#endif
