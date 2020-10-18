/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:47:11 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 20:46:05 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_double_exp(char *value_s, int exp_size)
{
	int	exp;
	int	i;
	int	bias;

	if (exp_size == 11)
		bias = 1023;
	else
		bias = 16383;
	i = exp_size - 1;
	exp = 0;
	while (i >= 0)
	{
		exp += (value_s[i] - '0') * ft_pow(2, exp_size - i - 1);
		i--;
	}
	exp -= bias;
	return (exp);
}
