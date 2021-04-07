/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/07 16:51:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	args_are_numeric(char *argv[])
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

t_int_list	*add_end_elem(t_int_list *head, t_int_list *new)
{
	t_int_list	*tmp;

	if (!head)
	{
		head = new;
		return (head);
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	return (head);
}

t_int_list	*allocate_new_elem(t_int_list *new)
{
	new = malloc(sizeof(t_int_list) * 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}
/*
t_int_list	*add_new_elem(t_int_list *head)
{
	t_int_list	*tmp;
	t_int_list	*new;

	if (!head)
	{
		head = malloc(sizeof(t_list) * 1);
		if (!head)
			free_and_exit(head, NULL, 3);
		head->next = NULL;
		return (head);
	}
	tmp = head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = malloc(sizeof(t_list) * 1);
	if (!new)
		free_and_exit(head, NULL, 3);
	tmp->next = new;
	new->next = NULL;
	return (head);
}
*/
t_int_list	*atoi_arg(t_int_list *a, char *arg)
{
	unsigned long int	i;
	unsigned long int	nb;
	long int			signe;
	t_int_list			*new;

	i = 0;
	while (arg && arg[i])
	{
		//printf("ARG: [%s]\n", arg);
		nb = 0;
		signe = 1;
		while (arg[i] == ' ')
			i++;
		if (arg[i] == '-')
		{
			signe = -signe;
			i++;
		}
		while (arg[i] >= '0' && arg[i] <= '9')
		{
			nb = (nb * 10) + (arg[i] - 48);
			i++;
		}
		//printf("arg i: [%c]\n", arg[i]);
		if (arg[i] != ' ' && i != ft_strlen(arg))
		{
			ft_putendl_fd("Error: syntax arg", 1);
			free_and_exit(a, NULL, 2);
		}
		new = allocate_new_elem(new);
		new->data = signe * nb;
		a = add_end_elem(a, new); //add error add_end
		//tmp = add_new_elem(tmp);
		//printf("NUMBER: %ld\n", signe * nb);
		//tmp->data = signe * nb;
		//printf("DATA: %d\n", tmp->data);
	}
	return (a);
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

int main(int argc, char *argv[])
{
	t_int_list	*a;
	t_int_list	*tmp;
	
	if (!args_are_numeric(argv))
	{
		ft_putendl_fd("Error: args not numeric", 1);
		return (1);
	}
	(void)argc;
	a = NULL;
	a = get_args(a, argv);
	tmp = a;
	while (tmp != NULL)
	{
		printf("ELEM: [%d]\n", tmp->data);
		tmp = tmp->next;
	}
	for (int i = 1; argv[i]; i++)
		printf("ARGV: [%s]\n", argv[i]);
	free_and_exit(a, NULL, 0);
	//for (int i = 1; argv[i]; i++)
	//	printf("MINE ATOI: [%d]\n", ft_atoi(argv[i]));
	//for (int i = 1; argv[i]; i++)
	//	printf("REAL ATOI: [%d]\n", atoi(argv[i]));
}
