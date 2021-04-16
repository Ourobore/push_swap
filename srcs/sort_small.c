/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:39:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 13:34:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_int_list **a, int mode)
{
	if (get_length_int_list(*a) == 2 && (*a)->data > (*a)->next->data)
		call_operation(a, NULL, "sa", mode);
	else if (get_length_int_list(*a) == 3)
	{
		if ((*a)->data == get_min_max(*a, 1)->data && !is_sorted(*a, 0))
		{
			call_operation(a, NULL, "ra", mode);
			if ((*a)->data > (*a)->next->data)
				call_operation(a, NULL, "sa", mode);
		}
		else if ((*a)->data > (*a)->next->data)
			call_operation(a, NULL, "sa", mode);
		else if ((*a)->data < (*a)->next->data)
		{
			if ((*a)->next->data == get_min_max(*a, 1)->data && \
				(*a)->data < (*a)->next->next->data)
			{
				call_operation(a, NULL, "sa", mode);
				call_operation(a, NULL, "ra", mode);
			}
			else
				call_operation(a, NULL, "rra", mode);
		}
	}
}

void	new_min_a(t_int_list **a, t_int_list **b, int len_a, int mode)
{
	t_int_list *min_a;

	min_a = get_min_max(*a, 0);
	if (get_distance(*a, min_a) < (len_a / 2) + 1)
		while (*a != min_a)
			call_operation(a, NULL, "ra", mode);
	else
		while (*a != min_a)
			call_operation(a, NULL, "rra", mode);
	call_operation(a, b, "pa", mode);
}

void	new_max_a(t_int_list **a, t_int_list **b, int len_a, int mode)
{
	t_int_list *min_a;
	t_int_list *max_a;

	min_a = get_min_max(*a, 0);
	max_a = get_min_max(*a, 1);
	if (get_distance(*a, max_a) < (len_a / 2) + 1)
		while (*a != min_a)
			call_operation(a, NULL, "ra", mode);
	else
		while (*a != min_a)
			call_operation(a, NULL, "rra", mode);
	call_operation(a, b, "pa", mode);
}

void	push_on_a_small(t_int_list **a, t_int_list **b, int length_a, int mode)
{
	t_int_list	*below;
	t_int_list	*above;

	below = get_closest(*a, *b, 0);
	above = get_closest(*a, *b, 1);
	if (get_distance(*a, below) < (length_a / 2) + 1)
		while (!(get_last_elem(*a) == below && *a == above))
			call_operation(a, NULL, "ra", mode);
	else
		while (!(get_last_elem(*a) == below && *a == above))
			call_operation(a, NULL, "rra", mode);
	call_operation(a, b, "pa", mode);
}

void	sort_small(t_int_list **a, t_int_list **b, int mode)
{
	int			length_a;

	while (get_length_int_list(*a) > 3)
		call_operation(a, b, "pb", mode);
	if (!is_sorted(*a, 0))
		sort_three(a, mode);
	while (*b)
	{
		length_a = get_length_int_list(*a);
		if ((*b)->data < get_min_max(*a, 0)->data)
			new_min_a(a, b, length_a, mode);
		else if ((*b)->data > get_min_max(*a, 1)->data)
			new_max_a(a, b, length_a, mode);
		else
			push_on_a_small(a, b, length_a, mode);
	}
	if (get_distance(*a, get_min_max(*a, 0)) < (length_a / 2) + 1)
		while (!is_sorted(*a, 0))
			call_operation(a, NULL, "ra", mode);
	else
		while (!is_sorted(*a, 0))
			call_operation(a, NULL, "rra", mode);
}
