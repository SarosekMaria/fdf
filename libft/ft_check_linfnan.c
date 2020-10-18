/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_linfnan.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:12:42 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 19:54:18 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_linfnan(char *s, t_struct *m)
{
	int		i;
	char	tmp[10];
	int		flag;

	flag = 0;
	i = 1;
	if (s[0] == '1')
		while (i < 64 && flag == 0)
		{
			if (s[i] != '0')
				flag = 1;
			i++;
		}
	if (flag == 0 && s[60] != '1')
		ft_strcpy(tmp, "inf");
	else
	{
		ft_strcpy(tmp, "nan");
		m->sign = 0;
		m->plus = 0;
		m->space = 0;
	}
	m->zero = 0;
	ft_buf_init_inff(tmp, m);
}
