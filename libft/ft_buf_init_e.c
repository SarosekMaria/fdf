/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_init_e.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 19:36:34 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 17:59:39 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_vspom2(t_struct *m, char *buf, int *len_buf, int *flag)
{
	if (m->space == 1 && m->sign == 0 && m->plus == 0)
	{
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
		(*len_buf)++;
	}
	else if (m->space == 1 && (m->sign == 1 || m->plus == 1) &&
			(*len_buf < m->width) && m->minus == 0)
	{
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
		(*len_buf)++;
	}
	if (m->hash == 1 && m->precisionft == 0)
	{
		*flag = 0;
		while (buf[*flag] == '+' || buf[*flag] == '-' || buf[*flag] == ' ')
			(*flag)++;
		while (buf[*flag] >= '0' && buf[*flag] <= '9')
			(*flag)++;
		buf[*flag] = '.';
	}
	if (*len_buf < m->width && m->minus == 1)
	{
		buf[*len_buf] = ' ';
		(*len_buf)++;
	}
}

static void	ft_vspom3(int *len_buf, char *buf, t_struct *m, int *flag)
{
	*len_buf += 3;
	ft_bzero(buf + *len_buf, 2);
	if (m->minus == 1 || *len_buf > m->width)
		ft_left_alignment(m, buf, len_buf);
	else
		ft_right_alignment(m, buf, len_buf, flag);
	ft_vspom2(m, buf, len_buf, flag);
	ft_putstr_fd(buf, m->fd);
	m->len += *len_buf;
}

void		ft_buf_init_e(char *int_part, char *frac_part, t_struct *m)
{
	char	*buf;
	int		len_ip;
	int		len_fp;
	int		len_buf;
	int		flag;

	flag = 0;
	if (m->sign == 1 || m->plus == 1 || m->space == 1)
		flag = 1;
	len_ip = ft_strlen(int_part);
	len_fp = ft_strlen(frac_part);
	buf = ft_strnew(len_ip + len_fp + m->width + m->precisionft + 10);
	if (buf == NULL)
		return ;
	buf[0] = int_part[0];
	buf[1] = '.';
	len_buf = ft_vspom4(buf, int_part, frac_part, m);
	ft_exp(&len_ip, buf, &len_buf);
	ft_vspom3(&len_buf, buf, m, &flag);
	ft_strdel(&buf);
}
