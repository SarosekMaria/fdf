/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 12:53:10 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/07 16:40:42 by mjohnsie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_print_octal(char conversion, t_struct *m)
{
	unsigned long long int	value;
	char					*buf;

	buf = NULL;
	value = 0;
	if (m->precision < 0)
		m->precision = 0;
	m->conversion = conversion;
	if (m->length == 0)
		value = (unsigned int)va_arg(m->ap, unsigned long long int);
	else if (m->length == 1)
		value = (unsigned short)va_arg(m->ap, unsigned long long int);
	else if (m->length == 2)
		value = (unsigned char)va_arg(m->ap, unsigned long long int);
	else if (m->length == 3)
		value = (unsigned long)va_arg(m->ap, unsigned long long int);
	else if (m->length == 4)
		value = va_arg(m->ap, unsigned long long int);
	else if (m->length == 6)
		value = va_arg(m->ap, uintmax_t);
	else if (m->length == 7)
		value = va_arg(m->ap, size_t);
	ft_itoa_base(value, 8, m, buf);
	m->i++;
}
