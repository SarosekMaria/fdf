/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_udecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:17:03 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 18:53:19 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_print_udecimal(char conversion, t_struct *m)
{
	unsigned long long int	value;
	char					*buf;

	buf = NULL;
	value = 0;
	if (m->precision < 0)
		m->precision = 0;
	m->conversion = conversion;
	if (m->length == 0 && m->conversion == 'u')
		value = (unsigned int)va_arg(m->ap, unsigned long long int);
	else if (m->length == 1 && m->conversion == 'u')
		value = (unsigned short)va_arg(m->ap, unsigned long long int);
	else if (m->length == 2 && m->conversion == 'u')
		value = (unsigned char)va_arg(m->ap, unsigned long long int);
	else if (m->length == 3 || m->conversion == 'U')
		value = (unsigned long)va_arg(m->ap, unsigned long long int);
	else if (m->length == 4)
		value = va_arg(m->ap, unsigned long long int);
	else if (m->length == 6)
		value = va_arg(m->ap, uintmax_t);
	else if (m->length == 7)
		value = va_arg(m->ap, size_t);
	ft_print_udec(m, value, buf);
}

void						ft_print_udec(t_struct *m,
		unsigned long long int value, char *buf)
{
	char					*tmp;

	tmp = ft_itoa_u(value);
	buf = ft_strnew(ft_strlen(tmp) + m->width + 10);
	ft_strcpy(buf, tmp);
	ft_strdel(&tmp);
	ft_buf_init_dioux(buf, m);
	ft_strdel(&buf);
	m->i++;
}
