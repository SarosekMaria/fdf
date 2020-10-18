/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_str_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:43:46 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 15:14:33 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_sum(int *id, int *i, char *dst)
{
	*i = *id;
	while (1)
	{
		if (dst[*i] >= '0' && dst[*i] <= '9')
			break ;
		dst[*i] = dst[*i] - 9 - 1;
		if (*i == 0)
			ft_bitwise_shift(dst, i, id);
		dst[*i - 1] += 1;
		(*i)--;
	}
}

char		*ft_sum_str_int(char *dst, char *src)
{
	int		id;
	int		is;
	int		i;

	i = 0;
	id = ft_strlen(dst) - 1;
	is = ft_strlen(src) - 1;
	if (id < 0)
		id = 0;
	while (is >= 0)
	{
		if (id < 0)
			ft_bitwise_shift(dst, &i, &id);
		dst[id] += src[is] - '0';
		if (dst[id] > '9')
			ft_sum(&id, &i, dst);
		id--;
		is--;
	}
	return (dst);
}
