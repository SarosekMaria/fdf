/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:17:03 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 16:09:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			ft_decision(t_struct *m, long long int *value)
{
	if (m->length == 0 && m->conversion != 'D')
		*value = (int)va_arg(m->ap, long long int);
	else if (m->length == 1 && m->conversion != 'D')
		*value = (short)va_arg(m->ap, long long int);
	else if (m->length == 2 && m->conversion != 'D')
		*value = (signed char)va_arg(m->ap, long long int);
	else if (m->length == 3 || m->conversion == 'D')
		*value = (long)va_arg(m->ap, long long int);
	else if (m->length == 4)
		*value = va_arg(m->ap, long long int);
	else if (m->length == 6)
		*value = va_arg(m->ap, intmax_t);
	else if (m->length == 7)
		*value = va_arg(m->ap, ssize_t);
	if (*value < 0)
		m->sign = 1;
}

void				ft_print_decimal(char conversion, t_struct *m)
{
	long long int	value;
	char			*buf;
	char			*tmp;

	buf = NULL;
	value = 0;
	if (m->precision < 0)
		m->precision = 0;
	m->conversion = conversion;
	ft_decision(m, &value);
	tmp = ft_itoa_s(value);
	buf = ft_strnew(ft_strlen(tmp) + m->width + m->precision + 1);
	ft_strcpy(buf, tmp);
	ft_strdel(&tmp);
	ft_buf_init_dioux(buf, m);
	ft_strdel(&buf);
	m->i++;
}
