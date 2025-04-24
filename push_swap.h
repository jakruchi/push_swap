/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 14:45:37 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/24 00:24:34 by jankruchina      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>	// malloc, free
# include <unistd.h>	// write

typedef struct s_list
{
	int				*data;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	int				min;
	int				max;
	int				size;
}					t_stack;

typedef struct s_stats
{
	t_stack			*a;
	t_stack			*b;
}					t_stats;

// cleaning.c
void	delete(int *content);
void	ft_lstclear(t_list **lst, void (*del)(int *));
void	free_wrong_input(void *number, t_list *list);
void	free_everything(t_list **a, t_list **b, t_stats *stats);

// compute_moves.c
int		compute_moves_in_a(t_list *node_to_check, t_stats *stats);
t_list	*get_lowest_dif_node(t_list *node_to_check, t_list *lst, int *position);
int		compute_moves_in_b(t_list *node_to_check, t_list *b, t_stats *stats);
int		compute_moves(t_list *node_to_check, t_list *stack_b, t_stats *stats);

// init_list.c
int		*init_number(t_list *list, char *input);
t_list	*init_node(int *number, t_list *list);
t_list	*init_list(int argc, char **argv);

// instructions.c
void	write_instruction(char first_letter, char last_letter);
void	swap(t_list **list, char c);
void	push(t_list **from, t_list **in, char c);
void	rotate(t_list **list, char c);
void	reverse_rotate(t_list **list, char c);

// list.c
t_list	*ft_lstnew(int *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);

// rotate.c
void	prepare_b(t_list *least_move, t_list **b, t_stats *stats);
void	move_node(t_list *least_move, t_list **a, t_list **b, t_stats *stats);
void	move_to_pos(t_list *least_move, t_list **a, t_list **b, t_stats *stats);
void	prepare_a(t_list **a, t_list **b, t_stats *stats);
void	final_rotate(t_list **lst, char letter, int extreme, int size_of_stack);

// safety.c
int		ft_safe_atoi(const char *str, int *error);
int		is_unique(t_list *list, int value);
int		is_sorted(t_list *lst);

// stats.c
void	update_substats(t_list *list, t_stack *sub_stats);
void	update_stats(t_list *a, t_list *b, t_stats *stats);
t_stats	*init_stats(t_list *stack_a);

// utils.c
void	node_goes_above(t_list **list, char letter, int position, int size);
void	node_goes_below(t_list **list, char letter, int position, int size);
void	prepare_twice_push(t_list **a, t_list **b, t_stats *stats);
int		find_position_of(int value, t_list *list);

#endif
