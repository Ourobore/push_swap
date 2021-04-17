/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:11:26 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 09:01:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		sort_quantile(t_int_list *a, t_int_list *b, \
					t_int_list **sorted_quantile, int **quantile)
{
	int	nb_quantile;

	*sorted_quantile = NULL;
	*sorted_quantile = copy_int_list(a);
	if (!(*sorted_quantile) || \
		get_length_int_list(*sorted_quantile) != get_length_int_list(a))
	{
		if (*sorted_quantile)
			free_int_list(*sorted_quantile);
		free_and_exit(a, b, 3);
	}
	sort_small(sorted_quantile, &b, 0);
	nb_quantile = (int)(get_length_int_list(a) * 0.015) + 4;
	*quantile = get_quantile(*sorted_quantile, nb_quantile);
	return (nb_quantile);
}

void	sorting_hub(t_int_list **a, t_int_list **b)
{
	t_int_list	*sorted_quantile;
	int			*quantile;
	int			nb_quantile;

	if (get_length_int_list(*a) < 30)
		sort_small(a, b, 1);
	else
	{
		nb_quantile = sort_quantile(*a, *b, &sorted_quantile, &quantile);
		if (quantile)
			sort_big(a, b, quantile, nb_quantile);
		else
		{
			free_int_list(sorted_quantile);
			exit(3);
		}
		free(quantile);
		free_int_list(sorted_quantile);
	}
}

int		main(int argc, char *argv[])
{
	t_int_list	*a;
	t_int_list	*b;

	(void)argc;
	a = NULL;
	b = NULL;
	a = get_args(a, argv);
	if (!a)
		free_and_exit(a, b, 0);
	sorting_hub(&a, &b);
	free_and_exit(a, b, 0);
}
