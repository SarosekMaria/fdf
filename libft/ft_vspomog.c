/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vspomog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 18:55:03 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 18:55:08 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_vspomog(char *buf, int *len_buf, t_struct *m, int *flag)
{
	if (m->minus == 1 || *len_buf > m->width)
		ft_left_alignment(m, buf, len_buf);
	else
		ft_right_alignment(m, buf, len_buf, flag);
	if (m->space == 1 && m->sign == 0 && m->plus == 0)
	{
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
		(*len_buf)++;
	}
	else if (m->space == 1 && (m->sign == 1 || m->plus == 1) &&
			(*len_buf < m->width) && m->minus == 0)
	{
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
		(*len_buf)++;
	}
	if (m->hash == 1 && m->precisionft == 0)
	{
		*flag = 0;
		while (buf[*flag] == '+' || buf[*flag] == '-' || buf[*flag] == ' ')
			(*flag)++;
		while (buf[*flag] >= '0' && buf[*flag] <= '9')
			(*flag)++;
		buf[*flag] = '.';
	}
}
