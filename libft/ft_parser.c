/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 19:22:43 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 20:58:38 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_parse_flags(const char *format, t_struct *list)
{
	while (ft_strchr("-+ 0#", format[list->i]))
	{
		if (format[list->i] == '-')
			list->minus = 1;
		else if (format[list->i] == '+')
			list->plus = 1;
		else if (format[list->i] == ' ')
			list->space = 1;
		else if (format[list->i] == '0')
			list->zero = 1;
		else if (format[list->i] == '#')
			list->hash = 1;
		list->i++;
	}
	if (ft_strstr(format, ".#") != NULL)
		list->zero = 0;
}

void			ft_parse_width(const char *format, t_struct *list)
{
	if (format[list->i] == '*')
	{
		list->width = va_arg(list->ap, int);
		list->minus = (list->width < 0) ? 1 : list->minus;
		list->width = (list->width < 0) ? -list->width : list->width;
		while (format[list->i] == '*')
			list->i++;
	}
	if (ft_isdigit(format[list->i]))
	{
		list->width = ft_atoi(&format[list->i]);
		while (ft_isdigit(format[list->i]))
		{
			list->i++;
			if (format[list->i] == '*')
			{
				list->width = va_arg(list->ap, int);
				list->width = (list->width < 0) ? -list->width : list->width;
				while (format[list->i] == '*')
					list->i++;
			}
		}
	}
}

void			ft_parse_precision(const char *format, t_struct *list)
{
	int			precision;

	if (format[list->i] == '.')
	{
		list->i++;
		list->precision = -1;
		list->precisionp = 1;
		if (ft_isdigit(format[list->i]))
			ft_pars_help(format, list);
		else if (format[list->i] == '*')
		{
			precision = va_arg(list->ap, int);
			if (precision >= 0)
				list->precision = precision;
			else
			{
				list->precision = precision * (-1);
				list->asterisk = 1;
			}
			while (format[list->i] == '*')
				list->i++;
		}
	}
}

void			ft_parse_length(const char *format, t_struct *list)
{
	int			verif;

	if (ft_strchr("hlLjz", format[list->i]))
	{
		verif = ft_kostyl2(format, list);
		if (format[list->i] == 'h' && format[list->i + 1] == 'h')
			ft_kostyl3(verif, list);
		else if (format[list->i] == 'h')
			ft_kostyl(verif, list);
		else if (format[list->i] == 'l' && format[list->i + 1] == 'l')
			ft_kostyl3(verif, list);
		else if (format[list->i] == 'l')
			ft_kostyl(verif, list);
		else if (format[list->i] == 'L')
			ft_kostyl(verif, list);
		else if (format[list->i] == 'j')
			ft_kostyl(verif, list);
		else if (format[list->i] == 'z')
			list->length = 7;
		list->i++;
	}
	if (ft_strchr("hlLjz", format[list->i]))
		list->lenp = 1;
}

void			ft_print(const char *format, t_struct *list)
{
	if (format[list->i] == 'd' || format[list->i] == 'i' ||
			format[list->i] == 'D')
		ft_print_decimal(format[list->i], list);
	else if (format[list->i] == 'o')
		ft_print_octal(format[list->i], list);
	else if (format[list->i] == 'u' || format[list->i] == 'U')
		ft_print_udecimal(format[list->i], list);
	else if (format[list->i] == 'x' || format[list->i] == 'X')
		ft_print_hex(format[list->i], list);
	else if (format[list->i] == 'p')
		ft_print_pointer(format, list);
	else if (format[list->i] == 'c' || format[list->i] == 'C')
		ft_print_char(format, list);
	else if (format[list->i] == 's' || format[list->i] == 'S')
		ft_print_string(format, list);
	else if (format[list->i] == 'f' || format[list->i] == 'e' ||
			format[list->i] == 'E' || format[list->i] == 'g' ||
			format[list->i] == 'G' || format[list->i] == 'F')
		ft_print_float(format[list->i], list);
	else if (format[list->i] == 'b')
		ft_print_binar(format, list);
	else if (format[list->i] == '%')
		ft_print_percent(format, list);
	else if (format[list->i] == 'r')
		ft_init_fd(list);
}
