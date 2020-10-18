/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_help.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjohnsie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 13:52:43 by mjohnsie          #+#    #+#             */
/*   Updated: 2019/12/07 15:11:00 by mjohnsie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_unbrlen(uintmax_t value, int base)
{
	int			i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

int				ft_nbr_len(intmax_t value, int base)
{
	int			i;

	i = 0;
	if (value == 0)
		return (1);
	if (value < -9223372036854775807)
		return (20);
	if (value < 0)
	{
		i++;
		value *= -1;
	}
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

int				ft_uitoa_base(uintmax_t value, int base, char x)
{
	int			len;
	uintmax_t	value2;
	char		*radix;
	char		*result;

	len = 1;
	value2 = value;
	while (value2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = (x == 'X') ?
	ft_strdup("0123456789ABCDEF") : ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	write(1, result, len);
	free(radix);
	free(result);
	return (len);
}

int				ft_unbr_len(uintmax_t value, int base)
{
	int			i;

	i = 0;
	if (value == 0)
		return (1);
	while (value > 0)
	{
		value /= base;
		i++;
	}
	return (i);
}

int				ft_uitoa_base_pf(int fd, uintmax_t value, int base, char x)
{
	int			len;
	uintmax_t	value2;
	char		*radix;
	char		*result;

	len = 1;
	value2 = value;
	while (value2 /= base)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (0);
	radix = (x == 'X') ?
		ft_strdup("0123456789ABCDEF") : ft_strdup("0123456789abcdef");
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = radix[value % base];
		value /= base;
	}
	len = ft_strlen(result);
	write(fd, result, len);
	free(radix);
	free(result);
	return (len);
}
