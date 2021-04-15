/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 10:39:47 by user42            #+#    #+#             */
/*   Updated: 2021/04/15 17:18:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		get_distance(t_int_list *head, t_int_list *target)
{
	t_int_list	*tmp;
	int			distance;

	tmp = head;
	distance = 0;
	while (tmp)
	{
		if (tmp == target)
			return (distance);
		distance++;
		tmp = tmp->next;
	}
	return (-1);
}

t_int_list	*get_closest(t_int_list *head, t_int_list *target, int mode)
{
	t_int_list	*tmp;
	t_int_list	*below;
	t_int_list	*above;

	below = get_min_max(head, 0);
	above = get_min_max(head, 1);
	tmp = head;
	if (get_length_int_list(head) < 2)
		return (head);
	//printf("exec closest\n");
	while (tmp)
	{
		if (mode == 0 && tmp->data > below->data && tmp->data < target->data)
			below = tmp;
		else if (mode == 1 && tmp->data < above->data && tmp->data > target->data)
			above = tmp;
		tmp = tmp->next;
	}
	//printf("IN TARGET: %d\tbelow: %d\tabove: %d\n", target->data, below->data, above->data);
	if (mode == 0)
		return (below);
	else
		return (above);
}

void	sort_three(t_int_list **a)
{
	if (get_length_int_list(*a) == 2 && (*a)->data > (*a)->next->data)
		call_operation(a, NULL, "sa", 1);
	if (get_length_int_list(*a) == 3)
	{
		if ((*a)->data == get_min_max(*a, 1)->data && !is_sorted(*a, 0))
		{
			call_operation(a, NULL, "ra", 1);
			if ((*a)->data > (*a)->next->data)
				call_operation(a, NULL, "sa", 1);
		}
		else if ((*a)->data > (*a)->next->data)
			call_operation(a, NULL, "sa", 1);
		else if ((*a)->data < (*a)->next->data)
		{
			if ((*a)->next->data == get_min_max(*a, 1)->data && \
				(*a)->data < (*a)->next->next->data)
			{
				call_operation(a, NULL, "sa", 1);
				call_operation(a, NULL, "ra", 1);
			}
			else
				call_operation(a, NULL, "rra", 1);
		}
	}
}

void	sort_small(t_int_list **a, t_int_list **b)
{
	while (get_length_int_list(*a) > 3)
		call_operation(a, b, "pb", 1);
	sort_three(a);
	while (*b)
	{
		if ((*b)->data < get_min_max(*a, 0)->data)
		{
			if (get_distance(*a, get_min_max(*a, 0)) < get_length_int_list(*a) / 2)
				while ((*a)->data != get_min_max(*a, 0)->data)
					call_operation(a, NULL, "ra", 1);
			else
				while ((*a)->data != get_min_max(*a, 0)->data)
					call_operation(a, NULL, "rra", 1);
			call_operation(a, b, "pa", 1);
			continue ;
		}
		if ((*b)->data > get_min_max(*a, 1)->data)
		{
			if (get_distance(*a, get_min_max(*a, 1)) < get_length_int_list(*a) / 2)
				while ((*a)->data != get_min_max(*a, 0)->data)
					call_operation(a, NULL, "ra", 1);
			else
				while ((*a)->data != get_min_max(*a, 0)->data)
					call_operation(a, NULL, "rra", 1);
			call_operation(a, b, "pa", 1);
			continue ;
		}
		if (get_distance(*a, get_closest(*a, *b, 0)) < get_length_int_list(*a) / 2)
			while (!(get_last_elem(*a) == get_closest(*a, *b, 0) && *a == get_closest(*a, *b, 1)))
				call_operation(a, NULL, "ra", 1);
		else
			while (!(get_last_elem(*a) == get_closest(*a, *b, 0) && *a == get_closest(*a, *b, 1)))
				call_operation(a, NULL, "rra", 1);
		call_operation(a, b, "pa", 1);
	}
	if (get_distance(*a, get_min_max(*a, 0)) < get_length_int_list(*a) / 2)
		while (!is_sorted(*a, 0))
			call_operation(a, NULL, "ra", 1);
	else
		while (!is_sorted(*a, 0))
			call_operation(a, NULL, "rra", 1);
}
