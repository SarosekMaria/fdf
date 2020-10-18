/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjohnsie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:58:39 by mjohnsie          #+#    #+#             */
/*   Updated: 2019/12/07 15:17:09 by mjohnsie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_binar(const char *format, t_struct *list)
{
	uintmax_t	nbr;

	nbr = 0;
	if (list->precision < 0)
		list->precision = 0;
	if (format[list->i] == 'b')
	{
		if (list->length == 0)
			nbr = va_arg(list->ap, unsigned int);
		else if (list->length == 2)
			nbr = (unsigned char)va_arg(list->ap, unsigned int);
		else if (list->length == 1)
			nbr = (unsigned short)va_arg(list->ap, unsigned int);
		else if (list->length == 3)
			nbr = va_arg(list->ap, unsigned long);
		else if (list->length == 4)
			nbr = va_arg(list->ap, unsigned long long);
		else if (list->length == 6)
			nbr = va_arg(list->ap, uintmax_t);
		else if (list->length == 7)
			nbr = va_arg(list->ap, size_t);
		ft_print_binar2(nbr, list);
	}
}

void			ft_print_binar2(uintmax_t nbr, t_struct *list)
{
	int			nbrlen;

	nbrlen = ft_unbr_len(nbr, 2);
	if (!list->minus)
	{
		while (list->width-- > nbrlen)
			list->len += write(list->fd, " ", 1);
	}
	list->len += write(list->fd, "0x", 2);
	if (nbr == 0 && !list->precision && list->precisionp)
	{
		list->i++;
		return ;
	}
	while ((nbrlen - 2) < list->precision--)
		list->len += write(list->fd, "0", 1);
	list->len += ft_uitoa_base_pf(list->fd, nbr, 2, 0);
	if (list->minus)
	{
		while (list->width-- > nbrlen)
			list->len += write(list->fd, " ", 1);
	}
	list->i++;
}
