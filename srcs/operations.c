/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:43:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 08:28:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_list(t_int_list **head)
{
	t_int_list	*tmp;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
	tmp->previous = *head;
	(*head)->previous = NULL;
	(*head)->last_elem = (*head)->next->last_elem;
}

void	push_list(t_int_list **head_1, t_int_list **head_2)
{
	t_int_list	*old_head_1;
	t_int_list	*old_head_2;

	if (!(*head_1))
		return ;
	old_head_1 = *head_1;
	old_head_2 = *head_2;
	if ((*head_1)->next)
	{
		(*head_1)->next->last_elem = (*head_1)->last_elem;
		*head_1 = (*head_1)->next;
		(*head_1)->previous = NULL;
	}
	else
		*head_1 = NULL;
	*head_2 = old_head_1;
	if (old_head_2)
		old_head_2->previous = *head_2;
	(*head_2)->next = old_head_2;
	if (old_head_2)
		(*head_2)->last_elem = (*head_2)->next->last_elem;
	else
		(*head_2)->last_elem = *head_2;
}

void	rotate_up(t_int_list **head, t_int_list *tmp, t_int_list *new_end)
{
	new_end = *head;
	tmp = (*head)->last_elem;
	*head = (*head)->next;
	(*head)->previous = NULL;
	tmp->next = new_end;
	new_end->previous = tmp;
	new_end->next = NULL;
	(*head)->last_elem = new_end;
}

void	rotate_down(t_int_list **head, t_int_list *tmp, t_int_list *new_end)
{
	while ((*head)->next->next)
		*head = (*head)->next;
	new_end = *head;
	*head = (*head)->next;
	(*head)->previous = NULL;
	(*head)->next = tmp;
	new_end->next = NULL;
	(*head)->last_elem = new_end;
}

void	rotate_list(t_int_list **head, int mode)
{
	t_int_list	*new_end;
	t_int_list	*tmp;

	tmp = *head;
	new_end = NULL;
	if (!(*head) || (*head)->next == NULL)
		return ;
	if (mode == 0)
		rotate_up(head, tmp, new_end);
	else if (mode == 1)
		rotate_down(head, tmp, new_end);
}
