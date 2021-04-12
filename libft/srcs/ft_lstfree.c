/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:48:17 by user42            #+#    #+#             */
/*   Updated: 2021/04/12 10:48:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstfree(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst;
		if (lst->content)
			free(lst->content);
		lst = lst->next;
		free(tmp);
	}
}
