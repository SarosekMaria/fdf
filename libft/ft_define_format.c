/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 13:26:08 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 19:54:55 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_define_format(char *int_part, char *frac_part, t_struct *m, int exp)
{
	int	len_ip;

	len_ip = ft_strlen(int_part);
	exp = len_ip - 1;
	if (exp < -4 || exp >= m->precision)
	{
		if (m->conversion == 'g')
			m->conversion = 'e';
		else
			m->conversion = 'E';
		ft_buf_init_e(int_part, frac_part, m);
	}
	else
		ft_buf_init_float(int_part, frac_part, m);
}
