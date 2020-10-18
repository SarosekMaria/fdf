/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vspom4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:57:09 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 17:58:35 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vspom4(char *buf, char *int_part, char *frac_part, t_struct *m)
{
	int	len_buf;
	int	len_ip;

	len_ip = ft_strlen(int_part);
	if (len_ip > 1)
		ft_strncpy(buf + 2, int_part + 1, m->precisionft);
	ft_strncpy(buf + len_ip + 1, frac_part, m->precisionft - len_ip + 1);
	len_buf = ft_strlen(buf);
	while (len_buf - 2 < m->precisionft + 1)
	{
		buf[len_buf] = '0';
		len_buf++;
	}
	buf[len_buf - 1] = m->conversion;
	if (len_ip > 1 || (len_ip == 1 && frac_part[0] == '0'))
		buf[len_buf] = '+';
	else
		buf[len_buf] = '-';
	return (len_buf);
}
