/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safety.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jankruchina <jankruchina@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 17:42:40 by jankruchina       #+#    #+#             */
/*   Updated: 2025/04/23 23:40:14 by jankruchina      ###   ########.fr       */
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

int	is_unique(t_list *list, int value)
{
	while (list)
	{
		if (*(list->data) == value)
			return (0);
		list = list->next;
	}
	return (1);
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
