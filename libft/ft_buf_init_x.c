/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_init_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:56:13 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 18:01:16 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_v3(int *len_buf, t_struct *m, char *buf, int *flag)
{
	if (m->space == 1 && m->sign == 0)
		(*len_buf)--;
	while (*len_buf < m->precision)
	{
		ft_bitwise_shift_buf(buf, *len_buf, '0');
		(*len_buf)++;
	}
	if (m->hash == 1 && *flag == 0)
		ft_if_hash(m, buf, len_buf);
	while (*len_buf < m->width)
	{
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
		(*len_buf)++;
	}
}

static void	ft_v2(int *len_buf, t_struct *m, char *buf, int *flag)
{
	if (m->zero == 1 && m->precision == 0)
	{
		if (m->hash == 1 && *flag == 0)
			m->width -= 2;
		while (*len_buf < m->width)
		{
			ft_bitwise_shift_buf(buf + m->sign, *len_buf, '0');
			(*len_buf)++;
		}
		if (m->hash == 1 && *flag == 0)
			ft_if_hash(m, buf, len_buf);
	}
	else if (m->precision > 0 || m->width > 0)
		ft_v3(len_buf, m, buf, flag);
}

static void	ft_v1(int *len_buf, t_struct *m, char *buf, int *flag)
{
	if (*len_buf == 1 && buf[0] == '0')
		*flag = 1;
	if ((m->plus == 1 && m->sign == 0) || (m->space == 1 && m->sign == 0))
	{
		(*len_buf)++;
		m->width--;
	}
	if (m->minus == 1 || *len_buf > m->width)
	{
		while (*len_buf < m->precision)
		{
			ft_bitwise_shift_buf(buf, *len_buf, '0');
			(*len_buf)++;
		}
		if (m->hash == 1 && *flag == 0)
			ft_if_hash(m, buf, len_buf);
		while (*len_buf < m->width)
		{
			buf[*len_buf] = ' ';
			(*len_buf)++;
		}
	}
	else if (m->minus == 0 || *len_buf < m->width)
		ft_v2(len_buf, m, buf, flag);
}

void		ft_buf_init_x(char *buf, t_struct *m, int len_buf)
{
	int	flag;

	flag = 0;
	ft_v1(&len_buf, m, buf, &flag);
	if (m->plus == 1 && m->sign == 0)
		ft_bitwise_shift_buf(buf, len_buf, '+');
	else if (m->space == 1 && m->sign == 0)
		ft_bitwise_shift_buf(buf, len_buf, ' ');
	if ((m->format[m->i - 1] == '.' ||
			(m->format[m->i - 1] == '0' && m->format[m->i - 2] == '.')))
	{
		if (buf[len_buf - 1] == '0' && m->width == 0 && m->minus == 0)
			buf[len_buf - 1] = '\0';
		else if (m->width > 0 && m->minus == 0)
			buf[len_buf - 1] = ' ';
		else if (m->minus == 1)
			buf[0] = ' ';
	}
	ft_putstr_fd(buf, m->fd);
	m->len += ft_strlen(buf);
}
