/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:53:52 by user42            #+#    #+#             */
/*   Updated: 2021/04/08 17:26:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_int_list	*a;
	t_int_list	*b;
	
	(void)argc;
	if (!args_are_numeric(argv))
	{
		ft_putendl_fd("Error: args not numeric", 1);
		return (1);
	}
	a = NULL;
	b = NULL;
	a = get_args(a, argv);
	
	int r = 1;
	char	*line;
	while ((r = get_next_line(1, &line)) != 0)
	{
		call_operation(&a, &b, line);
		print_list(a, "a: ");
		print_list(b, "b: ");
	}
	/*
	print_list(a, "a: ");
	printf("==========================\n");
	swap_list(&a);
	print_list(a, "a: ");
	printf("==========================\n");
	print_list(b, "b: ");
	printf("==========================\n");
	push_list(&a,&b);
	print_list(a, "a: ");
	print_list(b, "b: ");
	printf("==========================\n");
	rotate_list(&a, 1);
	print_list(a, "a: ");
	*/
	//for (int i = 1; argv[i]; i++)
	//	printf("ARGV: [%s]\n", argv[i]);
	free_and_exit(a, b, 0);
}
