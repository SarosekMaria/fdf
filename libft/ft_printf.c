/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:14:14 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 21:06:05 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_struct	*ft_initialize(t_struct *list)
{
	list->format = NULL;
	list->i = 0;
	list->len = 0;
	list->lenp = 0;
	list->fd = 1;
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precision = -1;
	list->precisionft = 6;
	list->precisionp = 0;
	list->length = 0;
	list->conversion = 'd';
	list->sign = 0;
	list->asterisk = 0;
	return (list);
}

void			ft_reset_struct(t_struct *list)
{
	list->minus = 0;
	list->plus = 0;
	list->space = 0;
	list->zero = 0;
	list->hash = 0;
	list->width = 0;
	list->precision = -1;
	list->precisionft = 6;
	list->precisionp = 0;
	list->length = 0;
	list->sign = 0;
	list->asterisk = 0;
}

int				ft_printf(const char *format, ...)
{
	t_struct	*list;
	int			len;

	if (!(list = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	list = ft_initialize(list);
	list->fd = 1;
	list->format = format;
	if (format)
	{
		va_start(list->ap, format);
		if (!ft_strchr(list->format, '%'))
			list->len += write(list->fd, list->format, ft_strlen(format));
		else
			list->len = ft_formatparse(format, list);
		va_end(list->ap);
	}
	len = list->len;
	free(list);
	return (len);
}

int				ft_formatparse(const char *format, t_struct *list)
{
	while (format[list->i] != '\0')
	{
		if (format[list->i] == '%')
		{
			if (format[list->i + 1] != '\0')
				list->i++;
			else
				return (list->len);
			while (ft_strchr("#-+ .*0123456789hlLjz", format[list->i]))
			{
				if (format[list->i + 1] == '\0')
					return (list->len);
				ft_parse(format, list);
			}
			if (ft_strchr("sSpdDioOuUxXcCbfFkreEgG%", format[list->i]))
				ft_printform(format, list);
		}
		else
		{
			if (list->lenp)
				return (list->len);
			ft_printdat(format, list);
		}
	}
	return (list->len);
}

void			ft_parse(const char *format, t_struct *list)
{
	ft_parse_flags(format, list);
	ft_parse_width(format, list);
	ft_parse_precision(format, list);
	ft_parse_length(format, list);
}
