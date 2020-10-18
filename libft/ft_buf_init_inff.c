/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_init_inff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:46:33 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 18:00:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_buf_init_inff(char *int_part, t_struct *m)
{
	char	*buf;
	int		len_ip;
	int		len_buf;
	int		flag;

	flag = 0;
	if (m->sign == 1 || m->plus == 1 || m->space == 1)
		flag = 1;
	len_ip = ft_strlen(int_part);
	buf = ft_strnew(len_ip + m->width + m->precisionft + 1);
	if (buf == NULL)
		return ;
	ft_strcpy(buf, int_part);
	len_buf = ft_strlen(buf);
	ft_vspomog(buf, &len_buf, m, &flag);
	if (len_buf < m->width && m->minus == 1)
	{
		buf[len_buf] = ' ';
		len_buf++;
	}
	ft_putstr_fd(buf, m->fd);
	m->len += len_buf;
	ft_strdel(&buf);
}
