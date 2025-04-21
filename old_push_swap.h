/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:02:43 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/07 21:27:02 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>	// malloc, free
#include <stdio.h>	// printf
#include <unistd.h>	// sleep
#include <signal.h> // signal

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// push_swap.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int	ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void*));
void	delete(void *content);
void ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
int	is_sorted(t_list *lst);
int	is_reversed_sorted(t_list *lst);
void	print_list(void *content);
void	add_5(void *content);
void	multiply_2(void *content);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void	*add_30(void *content);
int	ft_atoi(const char *nptr);
void	print_both_lists(t_list *A, t_list *B);
void	swap(t_list **list, char c);
void	swap_ss(t_list **A, t_list **B, char c);
void	push(t_list **from, t_list **in, char c);
void	rotate(t_list **list, char c);
void	rotate_rr(t_list **list_A, t_list **list_B, char c);
void	reverse_rotate(t_list **list, char c);
void	reverse_rotate_rr(t_list **list_A, t_list **list_B, char c);
int	*find_lowest_number(t_list *list, int *lowest);
int	*find_highest_number(t_list *list, int *highest);
void	push_a_all(t_list **list_A, t_list **list_B);
int	*find_lowest(t_list *A, t_list *B, int *num_ptr);
int	*find_highest(t_list *A, t_list *B, int *num_ptr);
int	find_possition(t_list *list, int *lowest);


// first_try.c
int	*find_lowest_number1(t_list *list, int *lowest);
void	first_try(t_list *list_A, t_list *list_B);

// second_try.c
void	second_try(t_list **list_A, t_list **list_B);

// third_try.c
void	third_try(t_list **A, t_list **B, int middle, int size);

#endif
