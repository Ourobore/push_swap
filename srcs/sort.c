/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:35:43 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 10:47:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	new_min_b(t_int_list **a, t_int_list **b, t_int_list *min_b, int len_b)
{
	if (get_distance(*b, min_b) < (len_b / 2) + 1)
		while (get_last_elem(*b) != min_b)
			call_operation(NULL, b, "rb", 1);
	else
		while (get_last_elem(*b) != min_b)
			call_operation(NULL, b, "rrb", 1);
	call_operation(a, b, "pb", 1);
}

void	new_max_b(t_int_list **a, t_int_list **b, t_int_list *max_b, int len_b)
{
	if (get_distance(*b, max_b) < (len_b / 2) + 1)
		while (*b != max_b)
			call_operation(NULL, b, "rb", 1);
	else
		while (*b != max_b)
			call_operation(NULL, b, "rrb", 1);
	call_operation(a, b, "pb", 1);
}

void	push_on_b(t_int_list **a, t_int_list **b)
{
	t_int_list	*min_b;
	t_int_list	*max_b;
	t_int_list	*below;
	t_int_list	*above;
	int			length_b;

	min_b = get_min_max(*b, 0);
	max_b = get_min_max(*b, 1);
	length_b = get_length_int_list(*b);
	if ((*a)->data < get_min_max(*b, 0)->data)
		new_min_b(a, b, min_b, length_b);
	else if ((*a)->data > get_min_max(*b, 1)->data)
		new_max_b(a, b, max_b, length_b);
	else
	{
		below = get_closest(*b, *a, 0);
		above = get_closest(*b, *a, 1);
		if (get_distance(*b, below) < (length_b / 2) + 1)
			while (get_last_elem(*b) != above && *b != below)
				call_operation(NULL, b, "rb", 1);
		else
			while (get_last_elem(*b) != above && *b != below)
				call_operation(NULL, b, "rrb", 1);
		call_operation(a, b, "pb", 1);
	}
}

void	push_on_a(t_int_list **a, t_int_list **b)
{
	t_int_list	*max_b;

	max_b = get_min_max(*b, 1);
	if (get_distance(*b, max_b) < (get_length_int_list(*b) / 2) + 1)
		while (*b != max_b)
			call_operation(NULL, b, "rb", 1);
	else
		while (*b != max_b)
			call_operation(NULL, b, "rrb", 1);
	while (*b)
		call_operation(a, b, "pa", 1);
}

void	sort_big(t_int_list **a, t_int_list **b, int *quantile, int nb_quantile)
{
	int			i;
	int			closest;

	i = 0;
	while (i < nb_quantile)
	{
		closest = closest_elem(*a, quantile[i]);
		if (closest == -1)
		{
			i++;
			continue ;
		}
		else if (closest == 0)
			while ((*a)->data > quantile[i])
				call_operation(a, NULL, "ra", 1);
		else if (closest == 1)
			while ((*a)->data > quantile[i])
				call_operation(a, NULL, "rra", 1);
		if (get_length_int_list(*b) < 2)
			call_operation(a, b, "pb", 1);
		else
			push_on_b(a, b);
	}
	push_on_a(a, b);
}
