/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sum_str_frac.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:25:40 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 15:23:51 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_ip(char *dst, int *i, char *int_part, int *ip)
{
	while (1)
	{
		if (dst[*i] >= '0' && dst[*i] <= '9')
			break ;
		dst[*i] = dst[*i] - 9 - 1;
		if (*i == 0)
		{
			int_part[*ip] += 1;
			ft_overflow_digit_check(int_part, *ip);
			break ;
		}
		else
			dst[*i - 1] += 1;
		(*i)--;
	}
}

static void	ft_initialization(int *id, int *is, char *dst, char *src)
{
	while (*id < *is)
	{
		(*id)++;
		dst[*id] = '0';
	}
	while (*is < *id)
	{
		(*is)++;
		src[*is] = '0';
	}
}

char		*ft_sum_str_frac(char *dst, char *src, char *int_part, int is)
{
	int		id;
	int		ip;
	int		i;

	i = 0;
	id = ft_strlen(dst) - 1;
	ip = ft_strlen(int_part) - 1;
	if (id < 0)
		id = 0;
	ft_initialization(&id, &is, dst, src);
	while (is >= 0)
	{
		dst[id] += src[is] - '0';
		if (dst[id] > '9')
		{
			i = id;
			ft_ip(dst, &i, int_part, &ip);
		}
		id--;
		is--;
	}
	return (dst);
}
