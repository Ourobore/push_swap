/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 09:55:44 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 13:11:29 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_int_list	*copy_int_list(t_int_list *head)
{
	t_int_list	*tmp;
	t_int_list	*new_head;
	t_int_list	*new_elem;

	new_head = NULL;
	tmp = head;
	while (tmp)
	{
		new_elem = allocate_new_elem(new_elem);
		new_elem->data = tmp->data;
		new_head = add_end_elem(new_head, new_elem);
		tmp = tmp->next;
	}
	return (new_head);
}

t_int_list	*get_last_elem(t_int_list *head)
{
	t_int_list	*tmp;

	tmp = head;
	if (!head)
		return (head);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_int_list	*get_min_max(t_int_list *a, int mode)
{
	t_int_list	*tmp;
	t_int_list	*min;
	t_int_list	*max;

	if (!a || !a->next)
		return (a);
	min = a;
	max = a;
	tmp = a->next;
	while (tmp)
	{
		if (mode == 0 && tmp->data < min->data)
			min = tmp;
		else if (mode == 1 && tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	if (mode == 0)
		return (min);
	else
		return (max);
}
