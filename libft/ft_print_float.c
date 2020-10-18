/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:41:29 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 20:17:28 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void						ft_double_sign(char c, t_struct *m)
{
	if (c == '1')
		m->sign = 1;
}

void						ft_double_to_strings(double value, t_struct *m,
		int num_bits, int exp_size)
{
	unsigned long long int	*double_in_int;
	int						i;
	char					value_s[num_bits + 10];
	int						exp;

	double_in_int = (unsigned long long int*)(&value);
	i = 0;
	while (i < num_bits)
	{
		if ((*double_in_int >> (num_bits - 1 - i)) & 1)
			value_s[i] = '1';
		else
			value_s[i] = '0';
		i++;
	}
	value_s[i] = '\0';
	ft_double_sign(value_s[0], m);
	exp = ft_double_exp(value_s + 1, exp_size);
	if (exp == 1024)
		ft_check_infnan(value_s + exp_size + 1, m);
	else
		ft_double_mantissa(value_s + exp_size + 1, exp, m);
}

static void					ft_get_bits(unsigned long long *ldouble_mantissa,
		char *value_s, int *num_bits, short int *ldouble_exp)
{
	int						i;

	i = 0;
	while (i < 64)
	{
		if ((*ldouble_mantissa >> i) & 1)
			value_s[*num_bits - 1 - i] = '1';
		else
			value_s[*num_bits - 1 - i] = '0';
		i++;
	}
	while (i < 80)
	{
		if ((*ldouble_exp >> i) & 1)
			value_s[*num_bits - 1 - i] = '1';
		else
			value_s[*num_bits - 1 - i] = '0';
		i++;
	}
}

void						ft_ldouble_to_strings(long double value,
		t_struct *m, int num_bits, int exp_size)
{
	unsigned long long int	*ldouble_mantissa;
	short int				*ldouble_exp;
	char					value_s[num_bits + 10];
	int						exp;

	ldouble_mantissa = (unsigned long long int*)(&value);
	ldouble_exp = (short int*)(&value) + 4;
	ft_get_bits(ldouble_mantissa, value_s, &num_bits, ldouble_exp);
	value_s[num_bits] = '\0';
	ft_double_sign(value_s[0], m);
	exp = ft_double_exp(value_s + 1, exp_size);
	if (exp == 16384)
		ft_check_linfnan(value_s + exp_size + 1, m);
	else
		ft_ldouble_mantissa(value_s + exp_size + 1, exp, m, value_s + 1);
}

void						ft_print_float(char conversion, t_struct *m)
{
	double					value_1;
	long double				value_2;

	if (m->precision >= 0)
		m->precisionft = m->precision;
	value_1 = 0.0;
	value_2 = 0.0;
	m->conversion = conversion;
	if (m->length == 0 || m->length == 3)
	{
		value_1 = va_arg(m->ap, double);
		ft_double_to_strings(value_1, m, 64, 11);
	}
	else if (m->length == 5)
	{
		value_2 = va_arg(m->ap, long double);
		if (m->format[m->i - 2] != 'l' && m->format[m->i - 2] != 'L')
			ft_ldouble_to_strings(value_2, m, 80, 15);
	}
	m->i++;
}
