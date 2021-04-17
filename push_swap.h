/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:49:50 by user42            #+#    #+#             */
/*   Updated: 2021/04/17 09:05:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct			s_int_list
{
	int					data;
	struct s_int_list	*last_elem;
	struct s_int_list	*previous;
	struct s_int_list	*next;
}						t_int_list;

/*
** sorting functions
*/
void					sort_big(t_int_list **a, t_int_list **b, \
									int *quantile, int nb_quantile);
void					sort_small(t_int_list **a, t_int_list **b, int mode);
int						is_sorted(t_int_list *a, int mode);
int						closest_elem(t_int_list *head, int max);
int						get_distance(t_int_list *head, t_int_list *target);
t_int_list				*get_closest(t_int_list *head, t_int_list *target, \
										int mode);
int						*get_quantile(t_int_list *sorted, int nb_quantile);
t_int_list				*sort_for_quantile(t_int_list *a);
void					quicksort(t_int_list **a, t_int_list **b);

/*
** checker functions
*/
t_list					*read_operations(void);
void					exec_operations(t_int_list **a, t_int_list **b, \
										t_list *operations);

/*
** int_list operations functions
*/
void					swap_list(t_int_list **head);
void					push_list(t_int_list **head_1, t_int_list **head_2);
void					rotate_list(t_int_list **head, int mode);
int						call_operation(t_int_list **a, t_int_list **b, \
										char *operation, int m);
int						call_double_operation(t_int_list **a, t_int_list **b, \
												char *operation);

/*
** int_list functions
*/
t_int_list				*allocate_new_elem(t_int_list *new);
t_int_list				*add_end_elem(t_int_list *head, t_int_list *new);
t_int_list				*copy_int_list(t_int_list *head);
void					print_list(t_int_list *head, char *s);
int						get_length_int_list(t_int_list *head);
t_int_list				*get_last_elem(t_int_list *head);
t_int_list				*get_min_max(t_int_list *a, int mode);
t_int_list				*get_closest(t_int_list *head, t_int_list *target, \
										int mode);
int						get_distance(t_int_list *head, t_int_list *target);

/*
** args functions
*/
int						args_are_numeric(char *argv[]);
int						no_duplicates(t_int_list *a);
t_int_list				*get_args(t_int_list *a, char *argv[]);
t_int_list				*atoi_arg(t_int_list *a, char *arg);
long int				get_number(long int *i, long int *sign, char *arg);

/*
** free functions
*/
void					free_int_list(t_int_list *head);
void					free_and_exit(t_int_list *a, t_int_list *b, int status);

#endif
