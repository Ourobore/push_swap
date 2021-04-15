/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quantile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:50:29 by user42            #+#    #+#             */
/*   Updated: 2021/04/15 21:50:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_int_list	*sort_for_quantile(t_int_list *a)
{
	t_int_list	*sorted;
	t_int_list	*new;
	t_int_list	*tmp;
	int			length_a;
	int			min;

	sorted = NULL;
	length_a = get_length_int_list(a);
	while (get_length_int_list(sorted) != length_a)
	{
		tmp = a;
		min = get_min_max(a, 1)->data;
		while (tmp)
		{
			if (tmp->data < min && \
				(!sorted || tmp->data > get_min_max(sorted, 1)->data))
				min = tmp->data;
			tmp = tmp->next;
		}
		new = NULL;
		new = allocate_new_elem(new);
		if (!new)
			return (sorted);
		new->data = min;
		sorted = add_end_elem(sorted, new);
	}
	return (sorted);
}

int		*get_quantile(t_int_list *sorted, int nb_quantile)
{
	int	*quantile;
	int	nb_elem;
	int	count;
	int	i;

	quantile = NULL;
	quantile = ft_calloc(sizeof(int), nb_quantile);
	if (!quantile)
		return (NULL);
	nb_elem = get_length_int_list(sorted) / nb_quantile;
	i = 0;
	count = 1;
	while (i != nb_quantile - 1 && sorted->next)
	{
		if (count == nb_elem)
		{
			quantile[i++] = sorted->data;
			count = 1;
		}
		else
			count++;
		sorted = sorted->next;
	}
	quantile[i] = get_last_elem(sorted)->data;
	return (quantile);
}