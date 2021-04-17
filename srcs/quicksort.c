/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 08:54:24 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 09:00:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_pivot(t_int_list **a, t_int_list **b, t_int_list *pivot)
{
	while (*a != pivot)
	{
		if ((*a)->data < pivot->data)
			call_operation(a, b, "pb", 1);
		else
			call_operation(a, b, "ra", 1);
	}
}

void	quicksort(t_int_list **a, t_int_list **b)
{
	t_int_list	*pivot;
	t_int_list	*last_b_head;

	last_b_head = *b;
	while (!is_sorted(*a, 0))
	{
		while (get_length_int_list(*a) > 1 && \
				(*a)->data == get_min_max(*a, 0)->data)
		{
			call_operation(a, b, "pb", 1);
			last_b_head = *b;
		}
		pivot = *a;
		call_operation(a, b, "ra", 1);
		get_pivot(a, b, pivot);
		while (*b != last_b_head)
			call_operation(a, b, "pa", 1);
	}
	while (*b)
		call_operation(a, b, "pa", 1);
}
