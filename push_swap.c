/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:11:26 by user42            #+#    #+#             */
/*   Updated: 2021/04/15 18:27:55 by user42           ###   ########.fr       */
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

void	sorting_hub(t_int_list **a, t_int_list **b)
{
	t_int_list	*sorted_quantile;
	int			*quantile;
	int			nb_quantile = 11;

	sorted_quantile = sort_for_quantile(*a);
	quantile = get_quantile(sorted_quantile, nb_quantile);
	//for(int i = 0; i < nb_quantile; i++)
	//	printf("q: %d\n", quantile[i]);
	sort_big(a, b, quantile, nb_quantile);
	//print_list(*a, "A FINAL: ");
	free(quantile);
	free_int_list(sorted_quantile);
}

int		main(int argc, char *argv[])
{
	t_int_list	*a;
	t_int_list	*b;

	(void)argc;
	a = NULL;
	b = NULL;
	a = get_args(a, argv);
	if (get_length_int_list(a) == 0)
		free_and_exit(a, b, 0);
	//print_list(a, "A BEFORE: ");
	//print_list(b, "B BEFORE: ");
	/*
	call_operation(&a, &b, "pb", 1);
	call_operation(&a, &b, "pb", 1);
	t_int_list *tmp = get_last_elem(a);
	//printf("tmp: %d\n", tmp->data);
	while (tmp)
	{
		printf("a: %d\n", tmp->data);
		tmp = tmp->previous;
	}
	tmp = get_last_elem(b);
	while (tmp)
	{
		printf("b: %d\n", tmp->data);
		tmp = tmp->previous;
	}
	*/
	sorting_hub(&a, &b);
	//sort_small(&a, &b);
	//print_list(a, "A AFTER: ");
	//print_list(b, "B AFTER: ");
	//quicksort(&a, &b);

	free_and_exit(a, b, 0);
}
