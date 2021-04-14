/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:43:23 by user42            #+#    #+#             */
/*   Updated: 2021/04/14 10:40:13 by user42           ###   ########.fr       */
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

void	swap_list(t_int_list **head)
{
	t_int_list	*tmp;

	if (get_length_int_list(*head) <= 1)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

void	push_list(t_int_list **head_1, t_int_list **head_2)
{
	t_int_list	*old_head_1;
	t_int_list	*old_head_2;

	if (get_length_int_list(*head_1) == 0)
		return ;
	old_head_1 = *head_1;
	old_head_2 = *head_2;
	*head_1 = old_head_1->next;
	old_head_1->next = old_head_2;
	*head_2 = old_head_1;
}

void	rotate_list(t_int_list **head, int mode)
{
	t_int_list	*new_end;
	t_int_list	*tmp;

	tmp = *head;
	if (!(*head) || (*head)->next == NULL)
		return ;
	if (mode == 0)
	{
		new_end = *head;
		*head = (*head)->next;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_end;
		new_end->next = NULL;
	}
	if (mode == 1)
	{
		while ((*head)->next->next)
			*head = (*head)->next;
		new_end = *head;
		*head = (*head)->next;
		(*head)->next = tmp;
		new_end->next = NULL;
	}
}
