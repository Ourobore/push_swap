/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchapren <lchapren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 09:43:26 by lchapren          #+#    #+#             */
/*   Updated: 2021/01/14 10:51:22 by lchapren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*pt_cpy;

	i = 0;
	pt_cpy = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!pt_cpy)
		return (pt_cpy);
	while (s1[i])
	{
		pt_cpy[i] = s1[i];
		i++;
	}
	pt_cpy[i] = 0;
	return (pt_cpy);
}
