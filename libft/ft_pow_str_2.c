/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_str_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:36:38 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 16:21:38 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_calc(int *i, int *d, char *tmp, int *flag)
{
	*i = *d - 1;
	while (*i >= 0)
	{
		tmp[*i] = ((tmp[*i] - '0') << 1) + '0';
		if (*flag == 1)
		{
			*flag = 0;
			tmp[*i] += 1;
		}
		if (tmp[*i] > '9')
		{
			tmp[*i] = tmp[*i] - 10;
			*flag = 1;
			if (*i == 0)
				ft_bitwise_shift(tmp, i, d);
		}
		(*i)--;
	}
}

char		*ft_pow_str_2(int degree, char *tmp, int *d)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	tmp = ft_strnew(degree + 1);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '1';
	if (degree == 0)
		return (tmp);
	*d = 1;
	while (degree > 0)
	{
		ft_calc(&i, d, tmp, &flag);
		degree--;
	}
	return (tmp);
}
