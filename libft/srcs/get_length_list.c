/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 12:42:34 by user42            #+#    #+#             */
/*   Updated: 2021/03/30 12:44:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		get_length_list(t_list *head)
{
	int	length;

	length = 0;
	while (head != NULL)
	{
		head = head->next;
		length++;
	}
	return (length);
}
