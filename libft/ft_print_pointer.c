/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjohnsie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:20:06 by mjohnsie          #+#    #+#             */
/*   Updated: 2019/12/10 18:54:07 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_pointer(const char *format, t_struct *list)
{
	uintmax_t		nbr;
	int				nbrlen;

	if (list->precision < 0)
		list->precision = 0;
	nbr = 0;
	if (format[list->i] == 'p')
		nbr = (long long)(va_arg(list->ap, void*));
	nbrlen = ft_unbrlen(nbr, 16) + 2;
	if (!list->minus)
		ft_printw(list, nbrlen);
	list->len += write(list->fd, "0x", 2);
	if (nbr == 0 && !list->precision && list->precisionp)
	{
		list->i++;
		return ;
	}
	while ((nbrlen - 2) < list->precision--)
		list->len += write(list->fd, "0", 1);
	list->len += ft_uitoa_base(nbr, 16, 'x');
	if (list->minus)
		ft_printw(list, nbrlen);
	list->i++;
}

void				ft_printw(t_struct *list, int nbrlen)
{
	while (list->width-- > nbrlen)
		list->len += write(list->fd, " ", 1);
}
