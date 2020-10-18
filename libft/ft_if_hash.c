/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_if_hash.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:24:56 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 20:48:35 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_if_hash(t_struct *m, char *buf, int *len_buf)
{
	if (m->conversion == 'o' && m->precision == 0)
	{
		ft_bitwise_shift_buf(buf, (*len_buf), '0');
		(*len_buf)++;
	}
	else if (m->conversion == 'o' && m->precision > 0 && buf[0] != '0')
	{
		ft_bitwise_shift_buf(buf, (*len_buf), '0');
		(*len_buf)++;
	}
	if (m->conversion == 'x')
	{
		ft_bitwise_shift_buf(buf, (*len_buf), 'x');
		ft_bitwise_shift_buf(buf, (*len_buf) + 1, '0');
		(*len_buf) += 2;
	}
	if (m->conversion == 'X')
	{
		ft_bitwise_shift_buf(buf, (*len_buf), 'X');
		ft_bitwise_shift_buf(buf, (*len_buf) + 1, '0');
		(*len_buf) += 2;
	}
}
