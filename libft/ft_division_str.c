/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_division_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:43:21 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 15:06:26 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			g_mod;

static void	ft_fill1(int *i, char *tmp, int *i_t, char *dividend)
{
	if (*i != 0)
	{
		tmp[*i_t] = '0';
		(*i_t)++;
	}
	tmp[*i_t] = ((dividend[*i] - '0') * 10 +
			(dividend[*i + 1] - '0')) / 2 + '0';
}

static void	ft_fill2(char *tmp, char *dividend, int *i, int *i_t)
{
	if (g_mod != 0)
	{
		tmp[*i_t] = (g_mod * 10 + (dividend[*i] - '0')) / 2 + '0';
		g_mod = (g_mod * 10 + (dividend[*i] - '0')) % 2;
	}
	else if (dividend[*i] == '0')
		tmp[*i_t] = '0';
	else if (dividend[*i] - '0' < 2)
	{
		ft_fill1(i, tmp, i_t, dividend);
		g_mod = ((dividend[*i] - '0') * 10 + (dividend[*i + 1] - '0')) % 2;
		(*i)++;
	}
	else
	{
		tmp[*i_t] = (dividend[*i] - '0') / 2 + '0';
		g_mod = (dividend[*i] - '0') % 2;
	}
	(*i)++;
	(*i_t)++;
}

static void	ft_fill3(int *i, int *i_t, char *tmp, char *dividend)
{
	*i = 0;
	*i_t = 0;
	g_mod = 0;
	ft_strclr(tmp);
	while (dividend[*i])
		ft_fill2(tmp, dividend, i, i_t);
	ft_strclr(dividend);
	ft_strcpy(dividend, tmp);
}

char		*ft_division_str(int degree, char *tmp, int *len)
{
	char	*dividend;
	int		i;
	int		i_t;
	int		d;

	if (degree < 0)
		degree *= -1;
	d = degree;
	dividend = NULL;
	dividend = ft_pow_str_10(degree, dividend);
	tmp = ft_strnew(degree + 100);
	if (dividend == NULL || tmp == NULL)
		return (NULL);
	while (degree > 0)
	{
		ft_fill3(&i, &i_t, tmp, dividend);
		degree--;
	}
	*len = ft_strlen(tmp);
	while (*len < d)
		ft_bitwise_shift(tmp, &i, len);
	ft_strdel(&dividend);
	return (tmp);
}
