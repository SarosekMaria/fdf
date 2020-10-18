/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow_digit_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:19:17 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/03 22:51:44 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_overflow_digit_check(char *dst, int id)
{
	int i;

	if (dst[id] > '9')
	{
		i = id;
		while (1)
		{
			if (dst[i] >= '0' && dst[i] <= '9')
				break ;
			dst[i] = dst[i] - 9 - 1;
			if (i == 0)
				ft_bitwise_shift(dst, &i, &id);
			dst[i - 1] += 1;
			i--;
		}
	}
}
