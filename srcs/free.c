/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:01:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 10:01:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_int_list(t_int_list *head)
{
	t_int_list	*tmp;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_and_exit(t_int_list *a, t_int_list *b, int status)
{
	if (a)
		free_int_list(a);
	if (b)
		free_int_list(b);
	exit(status);
}
