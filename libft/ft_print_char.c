/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:41:29 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/07 15:18:20 by mjohnsie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_char(const char *format, t_struct *list)
{
	unsigned char	c;
	wchar_t			wc;

	if ((format[list->i] == 'c' && list->length == 5) || format[list->i] == 'C')
	{
		wc = (wchar_t)va_arg(list->ap, wint_t);
		ft_print_w_char(wc, list);
	}
	else if (format[list->i] == 'c')
	{
		c = (unsigned char)va_arg(list->ap, int);
		ft_print_c_char(c, list);
	}
	list->i++;
}

void				ft_print_c_char(unsigned char c, t_struct *list)
{
	if (list->minus)
		list->len += write(list->fd, &c, 1);
	while (list->width > 1)
	{
		if (list->zero)
			list->len += write(list->fd, "0", 1);
		else 
			list->len += write(list->fd, " ", 1);
		list->width--;
	}
	if (!list->minus)
		list->len += write(list->fd, &c, 1);
}

void				ft_print_w_char(wchar_t wc, t_struct *list)
{
	int				size;

	if (wc < 0 || wc > 1114111)
	{
		list->len = -1;
		return ;
	}
	size = (wc <= 127) ? 1 : 0;
	size = (wc >= 128 && wc <= 2047) ? 2 : size;
	size = (wc >= 2048 && wc <= 65535) ? 3 : size;
	size = (wc >= 65536 && wc <= 1114111) ? 4 : size;
	if (list->minus)
		ft_writewchar(wc, list);
	while (list->width-- > size)
	{
		if (list->zero && list->minus)
			list->len += write(list->fd, "0", 1);
		else
			list->len += write(list->fd, " ", 1);
	}
	if (!list->minus)
		ft_writewchar(wc, list);
}

void				ft_writewchar(wchar_t wc, t_struct *list)
{
	char			wstr[4];

	if (wc <= 255)
		list->len += write(list->fd, &wc, 1);
	else if (wc <= 2047)
	{
		wstr[0] = ((wc >> 6) + 192);
		wstr[1] = ((wc & 63) + 128);
		list->len += write(list->fd, wstr, 2);
	}
	else if (wc <= 65535)
	{
		wstr[0] = ((wc >> 12) + 224);
		wstr[1] = (((wc >> 6) & 63) + 128);
		wstr[2] = ((wc & 63) + 128);
		list->len += write(list->fd, wstr, 3);
	}
	else if (wc <= 1114111)
	{
		wstr[0] = ((wc >> 18) + 240);
		wstr[1] = (((wc >> 12) & 63) + 128);
		wstr[2] = (((wc >> 6) & 63) + 128);
		wstr[3] = ((wc & 63) + 128);
		list->len += write(list->fd, wstr, 4);
	}
}
