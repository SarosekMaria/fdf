/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjohnsie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:20:06 by mjohnsie          #+#    #+#             */
/*   Updated: 2019/12/07 15:43:29 by mjohnsie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_percent(const char *format, t_struct *list)
{
	if (format[list->i] == '%')
	{
		if (list->minus)
			list->len += write(list->fd, "%", 1);
		while (list->width > 1)
		{
			if (list->zero && !list->minus)
				list->len += write(list->fd, "0", 1);
			else
				list->len += write(list->fd, " ", 1);
			list->width--;
		}
		if (!list->minus)
			list->len += write(list->fd, "%", 1);
		list->i++;
	}
}
