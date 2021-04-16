/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:11:26 by user42            #+#    #+#             */
/*   Updated: 2021/04/16 10:50:59 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort(t_int_list **a, t_int_list **b)
{
	t_int_list	*pivot;
	t_int_list	*last_b_head;

	last_b_head = *b;
	while (!is_sorted(*a, 0))
	{
		while (get_length_int_list(*a) > 1 && (*a)->data == get_min_max(*a, 0)->data)
		{
			call_operation(a, b, "pb", 1);
			last_b_head = *b;
		}
		pivot = *a;
		call_operation(a, b, "ra", 1);
		while (*a != pivot)
		{
			if ((*a)->data < pivot->data)
				call_operation(a, b, "pb", 1);
			else
				call_operation(a, b, "ra", 1);
		}
		while (*b != last_b_head)
			call_operation(a, b, "pa", 1);
	}
	while (*b)
		call_operation(a, b, "pa", 1);
}

static void	sorting_hub(t_int_list **a, t_int_list **b)
{
	t_int_list	*sorted_quantile;
	int			*quantile;
	int			nb_quantile = (int)(get_length_int_list(*a) * 0.015) + 4;

	if (get_length_int_list(*a) < 30)
		sort_small(a, b);
	else
	{
		sorted_quantile = sort_for_quantile(*a);
		if (!sorted_quantile || \
			get_length_int_list(*a) != get_length_int_list(sorted_quantile))
		{
			if (sorted_quantile)
				free_int_list(sorted_quantile);
			free_and_exit(*a, *b, 3);
		}
		quantile = get_quantile(sorted_quantile, nb_quantile);
		if (quantile)
			sort_big(a, b, quantile, nb_quantile);
		else
			ft_putendl_fd("Error", 1);
		free(quantile);
		free_int_list(sorted_quantile);
	}
}

int			main(int argc, char *argv[])
{
	t_int_list	*a;
	t_int_list	*b;

	(void)argc;
	a = NULL;
	b = NULL;
	a = get_args(a, argv);
	if (get_length_int_list(a) == 0)
		free_and_exit(a, b, 0);
	sorting_hub(&a, &b);
	free_and_exit(a, b, 0);
}
