/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kostyliivelosipedy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjohnsie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:14:01 by mjohnsie          #+#    #+#             */
/*   Updated: 2019/12/10 18:51:17 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_kostyl(int verif, t_struct *list)
{
	if (list->length < verif)
		list->length = verif;
}

int			ft_kostyl2(const char *format, t_struct *list)
{
	int		verif;

	if (format[list->i] == 'h' && format[list->i + 1] == 'h')
		verif = 2;
	else if (format[list->i] == 'h')
		verif = 1;
	else if (format[list->i] == 'l' && format[list->i + 1] == 'l')
		verif = 4;
	else if (format[list->i] == 'l')
		verif = 3;
	else if (format[list->i] == 'L')
		verif = 5;
	else if (format[list->i] == 'j')
		verif = 6;
	else
		verif = 0;
	return (verif);
}

void		ft_kostyl3(int verif, t_struct *list)
{
	if (list->length < verif)
		list->length = verif;
	list->i++;
}

void		ft_printdat(const char *format, t_struct *list)
{
	list->len += write(list->fd, &format[list->i], 1);
	list->i++;
}

void		ft_printform(const char *format, t_struct *list)
{
	ft_print(format, list);
	ft_reset_struct(list);
}
