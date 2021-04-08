/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:27:51 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 10:37:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int			args_are_numeric(char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' || argv[i][j] > '9') && \
				argv[i][j] != ' ' && argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_int_list	*get_args(t_int_list *a, char *argv[])
{
	int	i;

	i = 1;
	while (argv[i])
	{
		a = atoi_arg(a, argv[i]);
		i++;
	}
	return (a);
}

t_int_list	*atoi_arg(t_int_list *a, char *arg)
{
	long int	i;
	long int	nb;
	long int	sign;
	t_int_list	*new;

	i = 0;
	while (arg && arg[i])
	{
		sign = 1;
		nb = get_number(&i, &sign, arg);
		if ((arg[i] != ' ' && i != (int)ft_strlen(arg)) || \
			sign * nb < INT_MIN || sign * nb > INT_MAX)
		{
			ft_putendl_fd("Error", 1);
			free_and_exit(a, NULL, 2);
		}
		new = allocate_new_elem(new);
		new->data = sign * nb;
		a = add_end_elem(a, new);
	}
	return (a);
}

long int	get_number(long int *i, long int *sign, char *arg)
{
	long int	nb;

	nb = 0;
	while (arg[*i] == ' ')
		(*i)++;
	if (arg[*i] == '-')
	{
		*sign = -(*sign);
		(*i)++;
	}
	while (arg[*i] >= '0' && arg[*i] <= '9')
	{
		nb = (nb * 10) + (arg[*i] - 48);
		(*i)++;
	}
	return (nb);
}
