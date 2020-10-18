/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 11:08:16 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 16:16:08 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void					ft_begin_init(unsigned long long int *mod, char *s,
		int *i, unsigned long long int *n)
{
	*mod = 0;
	s[99] = '\0';
	*i = 98;
	if (*n == 0)
	{
		s[*i] = '0';
		(*i)--;
	}
}

void						ft_itoa_base(unsigned long long int nb, int base,
		t_struct *m, char *buf)
{
	int						i;
	char					s[100];
	unsigned long long int	n;
	unsigned long long int	mod;
	int						len;

	n = nb;
	ft_begin_init(&mod, s, &i, &n);
	while (n > 0)
	{
		mod = n % base;
		if (mod < 10)
			s[i] = mod + '0';
		else if (m->conversion == 'x')
			s[i] = 'a' + (mod % 10);
		else if (m->conversion == 'X')
			s[i] = 'A' + (mod % 10);
		n = n / base;
		i--;
	}
	len = 98 - i;
	buf = ft_strnew(m->width + m->precision + len + 3);
	ft_strcpy(buf, s + i + 1);
	ft_buf_init_dioux(buf, m);
	ft_strdel(&buf);
}
