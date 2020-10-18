/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:59:20 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 18:00:24 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_exp(int *len_ip, char *buf, int *len_buf)
{
	int	exp;

	exp = *len_ip - 1;
	if (exp <= 9)
	{
		buf[*len_buf + 1] = exp / 10 + '0';
		buf[*len_buf + 2] = exp % 10 + '0';
	}
	else if (exp >= 100 && exp < 1000)
	{
		buf[*len_buf + 3] = exp % 10 + '0';
		buf[*len_buf + 2] = (exp / 10) % 10 + '0';
		buf[*len_buf + 1] = (exp / 100) + '0';
		(*len_buf)++;
	}
	else if (exp >= 1000 && exp < 10000)
	{
		buf[*len_buf + 4] = exp % 10 + '0';
		buf[*len_buf + 3] = (exp / 10) % 10 + '0';
		buf[*len_buf + 2] = (exp / 100) % 10 + '0';
		buf[*len_buf + 1] = (exp / 1000) + '0';
		*len_buf += 2;
	}
}
