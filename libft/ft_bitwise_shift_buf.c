/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitwise_shift_buf.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:39:44 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 16:10:31 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bitwise_shift_buf(char *s, int len_buf, char c)
{
	int	ind;

	ind = len_buf;
	while (ind > 0)
	{
		s[ind] = s[ind - 1];
		ind--;
	}
	s[ind] = c;
}
