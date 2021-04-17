/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 07:32:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char *argv[])
{
	t_int_list	*a;
	t_int_list	*b;
	t_list		*operations;
	int			status;
	int			sorted;

	(void)argc;
	a = NULL;
	b = NULL;
	status = 0;
	a = get_args(a, argv);
	if (!a)
		free_and_exit(a, b, status);
	operations = read_operations();
	exec_operations(&a, &b, operations);
	sorted = is_sorted(a, 0);
	if (!sorted || get_length_int_list(b) != 0)
	{
		ft_putendl_fd("KO", 1);
		status = 6;
	}
	else
		ft_putendl_fd("OK", 1);
	ft_lstfree(operations);
	free_and_exit(a, b, status);
}

t_list	*read_operations(void)
{
	t_list	*operation_list;
	t_list	*new_operation;
	char	*operation;
	int		r;

	operation_list = NULL;
	r = 1;
	while (r != 0)
	{
		r = get_next_line(0, &operation);
		if (r == 0)
			break ;
		new_operation = malloc(sizeof(t_list) * 1);
		if (!new_operation)
		{
			ft_lstfree(operation_list);
			exit(3);
		}
		new_operation->content = operation;
		new_operation->next = NULL;
		ft_lstadd_back(&operation_list, new_operation);
	}
	free(operation);
	return (operation_list);
}

void	exec_operations(t_int_list **a, t_int_list **b, t_list *operations)
{
	t_list	*tmp;
	int		error;

	tmp = operations;
	while (tmp)
	{
		error = call_operation(a, b, (char *)tmp->content, 0);
		if (error)
		{
			ft_putendl_fd("Error", 2);
			ft_lstfree(operations);
			free_and_exit(*a, *b, 5);
		}
		tmp = tmp->next;
	}
}
