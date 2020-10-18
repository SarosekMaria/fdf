/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 16:00:44 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 21:40:34 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void						ft_len(unsigned long long int *nb, int *i)
{
	while (*nb)
	{
		*nb = (*nb) / 10;
		(*i)++;
	}
}

static void						ft_vspom_2(char *s, unsigned long long int *nb,
		int *i)
{
	s[(*i)] = '\0';
	(*i)--;
	while (*nb)
	{
		s[(*i)] = (char)(((*nb) % 10) + 48);
		(*nb) = (*nb) / 10;
		(*i)--;
	}
}

char							*ft_itoa_u(unsigned long long int n)
{
	char						*s;
	int							i;
	unsigned long long int		nb;

	nb = n;
	i = 0;
	if (nb == 0)
	{
		s = ft_strnew(1);
		s[0] = '0';
		return (s);
	}
	ft_len(&nb, &i);
	s = (char*)malloc(sizeof(char) * (i + 1));
	if (s == NULL)
		return (NULL);
	nb = n;
	ft_vspom_2(s, &nb, &i);
	return (s);
}
