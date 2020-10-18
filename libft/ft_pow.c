/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:39:33 by sassassi          #+#    #+#             */
/*   Updated: 2019/11/26 15:42:21 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int		ft_pow(int base, int degree)
{
	unsigned long long int	result;

	result = 1;
	if (degree == 0)
		return (1);
	while (degree > 0)
	{
		result *= base;
		degree--;
	}
	return (result);
}
