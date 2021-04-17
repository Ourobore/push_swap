/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quantile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 21:50:29 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 08:29:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_int_list	*sorted_new_elem(t_int_list **sorted, int new_value)
{
	t_int_list	*new;

	new = NULL;
	new = allocate_new_elem(new);
	if (!new)
		return (new);
	new->data = new_value;
	(*sorted) = add_end_elem(*sorted, new);
	return (new);
}

t_int_list	*sort_for_quantile(t_int_list *a)
{
	t_int_list	*sorted;
	t_int_list	*tmp;
	int			length_a;
	int			min;
	int			max_sorted;

	sorted = NULL;
	length_a = get_length_int_list(a);
	while (get_length_int_list(sorted) != length_a)
	{
		tmp = a;
		min = get_min_max(a, 1)->data;
		max_sorted = get_min_max(sorted, 1)->data;
		while (tmp)
		{
			if (tmp->data < min && \
				(!sorted || tmp->data > max_sorted))
				min = tmp->data;
			tmp = tmp->next;
		}
		if (!sorted_new_elem(&sorted, min))
			return (sorted);
	}
	return (sorted);
}

int			*get_quantile(t_int_list *sorted, int nb_quantile)
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
