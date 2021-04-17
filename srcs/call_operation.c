/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 08:14:16 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 08:14:35 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		call_operation(t_int_list **a, t_int_list **b, char *operation, int m)
{
	if (ft_strcmp(operation, "sa") == 0)
		swap_list(a);
	else if (ft_strcmp(operation, "sb") == 0)
		swap_list(b);
	else if (ft_strcmp(operation, "pa") == 0)
		push_list(b, a);
	else if (ft_strcmp(operation, "pb") == 0)
		push_list(a, b);
	else if (ft_strcmp(operation, "ra") == 0)
		rotate_list(a, 0);
	else if (ft_strcmp(operation, "rb") == 0)
		rotate_list(b, 0);
	else if (ft_strcmp(operation, "rra") == 0)
		rotate_list(a, 1);
	else if (ft_strcmp(operation, "rrb") == 0)
		rotate_list(b, 1);
	else if (call_double_operation(a, b, operation) == 0)
		return (1);
	if (m == 1)
		ft_putendl_fd(operation, 1);
	return (0);
}

int		call_double_operation(t_int_list **a, t_int_list **b, char *operation)
{
	if (ft_strcmp(operation, "ss") == 0)
	{
		swap_list(a);
		swap_list(b);
		return (1);
	}
	else if (ft_strcmp(operation, "rr") == 0)
	{
		rotate_list(a, 0);
		rotate_list(b, 0);
		return (1);
	}
	else if (ft_strcmp(operation, "rrr") == 0)
	{
		rotate_list(a, 1);
		rotate_list(b, 1);
		return (1);
	}
	return (0);
}
