/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjohnsie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:58:47 by mjohnsie          #+#    #+#             */
/*   Updated: 2019/12/10 20:58:14 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pars_help(const char *format, t_struct *list)
{
	list->precision = ft_atoi(&format[list->i]);
	while (ft_isdigit(format[list->i]))
		list->i++;
}

void	ft_init_fd(t_struct *list)
{
	list->fd = va_arg(list->ap, int);
	list->i++;
}
