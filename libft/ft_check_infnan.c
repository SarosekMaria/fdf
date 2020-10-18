/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_infnan.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:10:24 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 19:52:40 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_check_infnan(char *s, t_struct *m)
{
	int		i;
	char	tmp[10];
	int		flag;

	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != '0')
		{
			flag = 1;
			m->sign = 0;
			m->plus = 0;
			m->space = 0;
			break ;
		}
		i++;
	}
	if (flag == 0)
		ft_strcpy(tmp, "inf");
	else
		ft_strcpy(tmp, "nan");
	m->zero = 0;
	ft_buf_init_inff(tmp, m);
}
