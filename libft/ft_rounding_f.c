/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rounding_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:50:21 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 15:48:52 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_help(char *s, t_struct *m)
{
	if (s[m->precisionft + 1] > '4')
	{
		s[m->precisionft] += 1;
		ft_overflow_digit_check(s, m->precisionft);
	}
}

void		ft_check_g(t_struct *m, int *len_ip, int *sh, char *int_part)
{
	*len_ip = ft_strlen(int_part);
	*sh = 0;
	m->precision = m->precisionft;
	if (m->conversion == 'g' || m->conversion == 'G')
	{
		if (m->precisionft == 0)
			m->precisionft = 1;
		else if (m->precisionft > *len_ip)
			m->precisionft -= *len_ip;
		else
			m->precisionft--;
	}
	if (m->conversion == 'e' || m->conversion == 'E')
		*sh = *len_ip - 1;
}

static void	ft_decide_buf(t_struct *m, char *int_part, char *frac_part,
		int *exp)
{
	if (m->conversion == 'f' || m->conversion == 'F')
		ft_buf_init_float(int_part, frac_part, m);
	else if (m->conversion == 'g' || m->conversion == 'G')
		ft_define_format(int_part, frac_part, m, *exp);
	else if (m->conversion == 'e' || m->conversion == 'E')
		ft_buf_init_e(int_part, frac_part, m);
}

static void	ft_parity_check(char *tmp, char *int_part)
{
	tmp[0] = '1';
	if (int_part[ft_strlen(int_part) - 1] - '0' % 2 != 0)
		ft_sum_str_int(int_part, tmp);
}

void		ft_rounding_f(char *int_part, char *frac_part, t_struct *m,
		int exp)
{
	int		i;
	char	tmp[10000];
	int		sh;
	int		len_ip;

	i = 0;
	ft_bzero(tmp, 10000);
	ft_check_g(m, &len_ip, &sh, int_part);
	if (sh > m->precisionft || m->conversion == 'g' || m->conversion == 'G')
		ft_help(int_part, m);
	else if (frac_part[m->precisionft - sh] > '4')
	{
		if (m->precisionft - sh > 0)
		{
			tmp[m->precisionft - 1 - sh] = '1';
			while (i < m->precisionft - 1 - sh)
				tmp[i++] = '0';
			ft_sum_str_frac(frac_part, tmp, int_part, m->precisionft - 1 - sh);
		}
		else if (m->precisionft - sh == 0 && frac_part[0] > '4')
			ft_parity_check(tmp, int_part);
	}
	ft_decide_buf(m, int_part, frac_part, &exp);
}
