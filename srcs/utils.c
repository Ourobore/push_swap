/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 09:22:54 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 10:14:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			get_distance(t_int_list *head, t_int_list *target)
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
	while (tmp)
	{
		if (mode == 0 && tmp->data > below->data && tmp->data < target->data)
			below = tmp;
		else if (mode == 1 && tmp->data < above->data && \
				tmp->data > target->data)
			above = tmp;
		tmp = tmp->next;
	}
	if (mode == 0)
		return (below);
	else
		return (above);
}
