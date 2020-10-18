/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_mantissa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:54:50 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 16:59:43 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			g_len;
int			g_i;
char		*g_int_part;
char		*g_frac_part;

static char	*ft_neg_exp(char *tmp, int *exp, char *g_int_part,
		char *g_frac_part)
{
	tmp = ft_division_str(*exp, tmp, &g_len);
	if (tmp == NULL)
	{
		ft_strdel(&g_int_part);
		ft_strdel(&g_frac_part);
		return (NULL);
	}
	ft_sum_str_frac(g_frac_part, tmp, g_int_part, g_len - 1);
	ft_strdel(&tmp);
	return (tmp);
}

static void	ft_cycle1(char *s, int *exp, char *tmp)
{
	while (s[g_i] != '\0')
	{
		(*exp)--;
		if (s[g_i] - '0' == 1)
		{
			tmp = ft_division_str(*exp, tmp, &g_len);
			if (tmp == NULL)
			{
				ft_strdel(&g_int_part);
				ft_strdel(&g_frac_part);
				return ;
			}
			g_frac_part = ft_sum_str_frac(g_frac_part, tmp, g_int_part,
					g_len - 1);
			ft_strdel(&tmp);
		}
		g_i++;
	}
}

static void	ft_cycle2(char *s, int *exp, char *tmp)
{
	tmp = ft_pow_str_2(*exp, tmp, &g_len);
	if (tmp == NULL)
	{
		ft_del(&g_int_part, &g_frac_part);
		return ;
	}
	ft_sum_str_int(g_int_part, tmp);
	ft_strdel(&tmp);
	g_i = 0;
	while (s[g_i] && *exp > 0)
	{
		(*exp)--;
		if (s[g_i] - '0' == 1)
		{
			tmp = ft_pow_str_2(*exp, tmp, &g_len);
			if (tmp == NULL)
			{
				ft_del(&g_int_part, &g_frac_part);
				return ;
			}
			ft_sum_str_int(g_int_part, tmp);
			ft_strdel(&tmp);
		}
		g_i++;
	}
}

static void	ft_cycle3(char *s, int *exp, char *tmp)
{
	while (s[g_i] != '\0')
	{
		(*exp)--;
		if (s[g_i] - '0' == 1)
		{
			tmp = ft_division_str(*exp, tmp, &g_len);
			if (tmp == NULL)
			{
				ft_del(&g_int_part, &g_frac_part);
				return ;
			}
			g_frac_part = ft_sum_str_frac(g_frac_part, tmp, g_int_part,
					g_len - 1);
			ft_strdel(&tmp);
		}
		g_i++;
	}
}

void		ft_double_mantissa(char *s, int exp, t_struct *m)
{
	char	*tmp;

	g_len = 0;
	g_i = 0;
	tmp = NULL;
	g_int_part = ft_strnew(5000);
	g_frac_part = ft_strnew(5000);
	g_int_part[0] = '0';
	g_frac_part[0] = '0';
	if (exp < 0)
	{
		tmp = ft_neg_exp(tmp, &exp, g_int_part, g_frac_part);
		ft_cycle1(s, &exp, tmp);
	}
	else if (exp >= 0)
	{
		ft_cycle2(s, &exp, tmp);
		ft_cycle3(s, &exp, tmp);
	}
	ft_rounding_f(g_int_part, g_frac_part, m, exp);
	ft_strdel(&g_int_part);
	ft_strdel(&g_frac_part);
}
