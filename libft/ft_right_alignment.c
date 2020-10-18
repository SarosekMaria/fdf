/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_right_alignment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:07:49 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 18:47:19 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_right_alignment(t_struct *m, char *buf, int *len_buf, int *flag)
{
	if (m->zero == 1)
		while (*len_buf < m->width - *flag)
		{
			ft_bitwise_shift_buf(buf, *len_buf, '0');
			(*len_buf)++;
		}
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
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
		(*len_buf)++;
	}
}
