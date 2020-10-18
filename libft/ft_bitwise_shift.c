/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise_shift.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:36:40 by sassassi          #+#    #+#             */
/*   Updated: 2019/11/27 16:19:08 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bitwise_shift(char *s, int *i, int *id)
{
	int	ind;

	ind = ft_strlen(s);
	while (ind > 0)
	{
		s[ind] = s[ind - 1];
		ind--;
	}
	s[ind] = '0';
	if (i != NULL)
		(*i)++;
	if (id != NULL)
		(*id)++;
}
