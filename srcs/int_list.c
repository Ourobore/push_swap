/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:02:22 by user42            #+#    #+#             */
/*   Updated: 2021/04/15 09:51:27 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_int_list	*allocate_new_elem(t_int_list *new)
{
	new = malloc(sizeof(t_int_list) * 1);
	if (!new)
		return (NULL);
	new->previous = NULL;
	new->next = NULL;
	return (new);
}

t_int_list	*add_end_elem(t_int_list *head, t_int_list *new)
{
	t_int_list	*tmp;

	if (!head)
	{
		head = new;
		return (head);
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
	return (head);
}

int			get_length_int_list(t_int_list *head)
{
	int	length;

	length = 0;
	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	return (length);
}

void		print_list(t_int_list *head, char *s)
{
	t_int_list	*tmp;

	tmp = head;
	while (tmp)
	{
		ft_putstr_fd(s, 1);
		ft_putnbr_fd(tmp->data, 1);
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

int			is_sorted(t_int_list *head, int mode)
{
	t_int_list	*tmp;
	int			previous;

	if (!head)
		return (1);
	tmp = head->next;
	previous = head->data;
	while (tmp)
	{
		if (mode == 0 && tmp->data < previous)
			return (0);
		else if (mode == 1 && tmp->data > previous)
			return (0);
		previous = tmp->data;
		tmp = tmp->next;
	}
	return (1);
}
