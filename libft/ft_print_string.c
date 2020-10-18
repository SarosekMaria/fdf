/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:48:51 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 21:21:42 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_print_string(const char *format, t_struct *list)
{
	char			*str;
	wchar_t			*wstr;

	if ((format[list->i] == 's' && (list->length == 5 || list->length == 3)) ||
			format[list->i] == 'S')
	{
		wstr = va_arg(list->ap, wchar_t *);
		ft_wstring(wstr, list);
	}
	else if (format[list->i] == 's')
	{
		str = va_arg(list->ap, char *);
		ft_string(str, list);
	}
	list->i++;
}

void				ft_string(char *str, t_struct *list)
{
	int				strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (strlen > 0 && strlen > list->precision && list->precision >= 0)
		strlen = list->precision;
	else if (list->precision && strlen > 0 && strlen > list->precision &&
			(list->format[list->i - 1] == '.' ||
			(list->format[list->i - 1] == '0' &&
			list->format[list->i - 2] == '.')))
		strlen = 0;
	if (list->minus)
		list->len += write(list->fd, str, strlen);
	while (list->width > strlen)
	{
		if (list->zero && !list->minus)
			list->len += write(list->fd, "0", 1);
		else
			list->len += write(list->fd, " ", 1);
		list->width--;
	}
	if (!list->minus)
		list->len += write(list->fd, str, strlen);
}

void				ft_wstring(wchar_t *wstr, t_struct *list)
{
	int				wstrlen;

	if (list->precision < 0)
		list->precision = 0;
	if (!wstr)
		wstr = L"(null)";
	wstrlen = ft_wstrlen(wstr, list);
	if (list->precision && wstrlen > 0 && wstrlen > list->precision)
		wstrlen = list->precision;
	if (list->len == -1)
		return ;
	if (list->minus)
		ft_putwstr(wstr, list, wstrlen);
	while (list->width > wstrlen)
	{
		if (list->zero)
			list->len += write(list->fd, "0", 1);
		else
			list->len += write(list->fd, " ", 1);
		list->width--;
	}
	if (!list->minus)
		ft_putwstr(wstr, list, wstrlen);
}

void				ft_putwstr(wchar_t *wstr, t_struct *list, int max)
{
	int				i;
	int				size;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] >= 128 && wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] >= 2048 && wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] >= 65536 && wstr[i] <= 1114111)
			size += 4;
		if (size <= max)
			ft_writewchar(wstr[i], list);
		else
			break ;
		i++;
	}
}

int					ft_wstrlen(wchar_t *wstr, t_struct *list)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			len += 1;
		else if (wstr[i] >= 128 && wstr[i] <= 2047)
			len += 2;
		else if (wstr[i] >= 2048 && wstr[i] <= 65535)
			len += 3;
		else if (wstr[i] >= 65536 && wstr[i] <= 1114111)
			len += 4;
		else
			list->len = -1;
		i++;
	}
	return (len);
}
