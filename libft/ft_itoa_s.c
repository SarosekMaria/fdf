/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 21:07:27 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 21:41:06 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_vspom(long long n, long long *nb, int *i)
{
	if (n < 0)
	{
		*nb = (*nb) * (-1);
		(*i)++;
	}
	while (*nb)
	{
		*nb = (*nb) / 10;
		(*i)++;
	}
}

static char	*ft_help(char *s)
{
	s[0] = '-';
	s[1] = '9';
	s[2] = '2';
	s[3] = '2';
	s[4] = '3';
	s[5] = '3';
	s[6] = '7';
	s[7] = '2';
	s[8] = '0';
	s[9] = '3';
	s[10] = '6';
	s[11] = '8';
	s[12] = '5';
	s[13] = '4';
	s[14] = '7';
	s[15] = '7';
	s[16] = '5';
	s[17] = '8';
	s[18] = '0';
	s[19] = '8';
	s[20] = '\0';
	return (s);
}

static void	ft_vspom_2(long long int n, char *s, long long *nb, int *i)
{
	if (n < 0)
	{
		s[0] = '-';
		*nb = -n;
	}
	s[(*i)] = '\0';
	(*i)--;
	while (*nb)
	{
		s[(*i)] = (char)(((*nb) % 10) + 48);
		(*nb) = (*nb) / 10;
		(*i)--;
	}
}

char		*ft_itoa_s(long long int n)
{
	char			*s;
	int				i;
	long long int	nb;

	nb = n;
	i = 0;
	if (nb == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
		return (s);
	}
	ft_vspom(n, &nb, &i);
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	nb = n;
	ft_vspom_2(n, s, &nb, &i);
	if (s[1] != '\0' && !(s[1] >= '0' && s[1] <= '9'))
		ft_help(s);
	return (s);
}
