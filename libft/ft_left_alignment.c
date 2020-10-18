/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_left_alignment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:05:27 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 18:45:17 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_left_alignment(t_struct *m, char *buf, int *len_buf)
{
	if (m->plus == 1)
	{
		if (m->sign == 0)
			ft_bitwise_shift_buf(buf, *len_buf, '+');
		else
			ft_bitwise_shift_buf(buf, *len_buf, '-');
		(*len_buf)++;
	}
	else if (m->sign == 1)
	{
		ft_bitwise_shift_buf(buf, *len_buf, '-');
		(*len_buf)++;
	}
	while (*len_buf < m->width - m->space)
	{
		buf[*len_buf] = ' ';
		(*len_buf)++;
	}
}
