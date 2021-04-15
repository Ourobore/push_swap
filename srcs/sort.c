/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 14:35:43 by user42            #+#    #+#             */
/*   Updated: 2021/04/15 18:25:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		closest_elem(t_int_list *head, int max)
{
	t_int_list	*tmp;
	int			length_head;
	int			count;
	int			start;
	int			end;

	tmp = head;
	count = 0;
	start = -1;
	end = -1;
	length_head = get_length_int_list(head);
	while (tmp && start == -1 && count < (length_head / 2) + 1)
	{
		if (tmp->data <= max)
			start = count;
		count++;
		tmp = tmp->next;
	}
	count = 1;
	tmp = get_last_elem(head);
	while (tmp && end == -1 && count < (length_head / 2) + 1)
	{
		//printf("max[%d] data: %d\n", max, tmp->data);
		if (tmp->data <= max)
			end = count;
		count++;
		tmp = tmp->previous;
	}
	//printf("start: %d\tend: %d\n", start, end);
	if (start != -1 && (start <= end || end == -1))
		return (0);
	else if (end != -1 && (end < start || start == -1))
		return (1);
	else
		return (-1);
}

void	sort_big(t_int_list **a, t_int_list **b, int *quantile, int nb_quantile)
{
	int	i;
	t_int_list	*below;
	t_int_list	*above;

	i = 0;
	while (i < nb_quantile)
	{
		//printf("quantile[%d]: %d\n", i, quantile[i]);
		//print_list(*a, "a debug: ");
		//printf("======\n");
		//print_list(*b, "b debug: ");
		if (closest_elem(*a, quantile[i]) == -1) // get smallest and nearest elem
		{
			i++;
			continue ;
		}
		else if (closest_elem(*a, quantile[i]) == 0)
		{
			//printf("here ra\n");
			//exit(1);
			while ((*a)->data > quantile[i])
				call_operation(a, NULL, "ra", 1);
		}
		else if (closest_elem(*a, quantile[i]) == 1)
		{
			//printf("here rra\n");
			//printf("quantile[%d]: %d\n", i, quantile[i]);
			//print_list(*a, "a debug: ");
			///exit(1);
			while ((*a)->data > quantile[i])
				call_operation(a, NULL, "rra", 1);
		}
		if (get_length_int_list(*b) < 2)
		{
			//printf("here pb\n");
			call_operation(a, b, "pb", 1);
		}
		else
		{ //push b
			if ((*a)->data < get_min_max(*b, 0)->data) // if new min
			{
				//printf("here new min\n");
				if (get_distance(*b, get_min_max(*b, 0)) < get_length_int_list(*b) / 2)
					while (get_last_elem(*b) != get_min_max(*b, 0))
						call_operation(NULL, b, "rb", 1);
				else
					while (get_last_elem(*b) != get_min_max(*b, 0))
						call_operation(NULL, b, "rrb", 1);
				call_operation(a, b, "pb", 1);
			}
			else if ((*a)->data > get_min_max(*b, 1)->data) //if new max
			{
				//printf("here new max\n");
				if (get_distance(*b, get_min_max(*b, 1)) < get_length_int_list(*b) / 2)
					while (*b != get_min_max(*b, 1))
						call_operation(NULL, b, "rb", 1);
				else
					while (*b != get_min_max(*b, 1))
						call_operation(NULL, b, "rrb", 1);
				call_operation(a, b, "pb", 1);
			}
			else //push b in correct position
			{
				below = get_closest(*b, *a, 0);
				above = get_closest(*b, *a, 1);
				//printf("[%d] below: %d\tabove: %d\n", (*a)->data, below->data, above->data);
				if (get_distance(*b, below) < get_length_int_list(*b) / 2)
					while (get_last_elem(*b) != above && *b != below)
						call_operation(NULL, b, "rb", 1);
				else
					while (get_last_elem(*b) != above && *b != below)
						call_operation(NULL, b, "rrb", 1);
				call_operation(a, b, "pb", 1);	
			}
		}
	}
	if (get_distance(*b, get_min_max(*b, 1)) < get_length_int_list(*b) / 2)
		while (*b != get_min_max(*b, 1))
			call_operation(NULL, b, "rb", 1);
	else
		while (*b != get_min_max(*b, 1))
			call_operation(NULL, b, "rrb", 1);

	while (*b)
		call_operation(a, b, "pa", 1);
}