/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_str_10.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:34:27 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 21:31:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pow_str_10(int degree, char *tmp)
{
	int i;

	i = 1;
	tmp = ft_strnew(degree + 10);
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '1';
	if (degree == 0)
		return (tmp);
	while (degree > 0)
	{
		tmp[i] = '0';
		i++;
		degree--;
	}
	return (tmp);
}
