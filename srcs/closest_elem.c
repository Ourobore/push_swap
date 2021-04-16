/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_elem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:08:02 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 10:16:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	closest_start(t_int_list *head, int length_head, int max)
{
	int	start;
	int	count;

	start = -1;
	count = 0;
	while (head && start == -1 && count < (length_head / 2) + 1)
	{
		if (head->data <= max)
			start = count;
		count++;
		head = head->next;
	}
	return (start);
}

static int	closest_end(t_int_list *head, int length_head, int max)
{
	int	end;
	int	count;

	end = -1;
	count = 1;
	while (head && end == -1 && count < (length_head / 2) + 1)
	{
		if (head->data <= max)
			end = count;
		count++;
		head = head->previous;
	}
	return (end);
}

int			closest_elem(t_int_list *head, int max)
{
	t_int_list	*tmp;
	int			length_head;
	int			start;
	int			end;

	length_head = get_length_int_list(head);
	tmp = head;
	start = closest_start(tmp, length_head, max);
	tmp = get_last_elem(head);
	end = closest_end(tmp, length_head, max);
	if (start != -1 && (start <= end || end == -1))
		return (0);
	else if (end != -1 && (end < start || start == -1))
		return (1);
	else
		return (-1);
}
