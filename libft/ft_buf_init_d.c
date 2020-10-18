/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_init_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:47:33 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 17:58:32 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_la(t_struct *m, int *len_buf, char *buf)
{
	if ((m->plus == 1 && m->sign == 0) ||
			(m->space == 1 && m->sign == 0))
		(*len_buf)--;
	while (*len_buf < m->precision)
	{
		ft_bitwise_shift_buf(buf, *len_buf, '0');
		(*len_buf)++;
	}
	if (m->plus == 1 && m->sign == 0)
		ft_bitwise_shift_buf(buf, *len_buf, '+');
	else if (m->space == 1 && m->sign == 0)
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
	if ((m->plus == 1 && m->sign == 0) ||
			(m->space == 1 && m->sign == 0))
		(*len_buf)++;
	if (m->sign == 2)
		m->width--;
	while (*len_buf < m->width)
	{
		buf[*len_buf] = ' ';
		(*len_buf)++;
	}
}

static void	ft_ravspom(t_struct *m, int *len_buf, char *buf, int *flag)
{
	if ((m->plus == 1 && m->sign == 0) || (m->space == 1 && m->sign == 0))
		(*len_buf)++;
	if (m->plus == 1 && m->sign == 0 && *flag == 0)
		ft_bitwise_shift_buf(buf, *len_buf, '+');
	else if (m->plus == 1 && m->sign == 0 && *len_buf == 2 &&
			buf[0] == '0' && *flag == 1)
		buf[0] = '+';
	else if (m->space == 1 && m->sign == 0)
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
	else if (m->sign == 2)
	{
		ft_bitwise_shift_buf(buf, *len_buf, '-');
		(*len_buf)++;
		m->sign = 3;
	}
	while (*len_buf < m->width)
	{
		ft_bitwise_shift_buf(buf, *len_buf, ' ');
		(*len_buf)++;
	}
}

static void	ft_ra(t_struct *m, int *len_buf, char *buf, int *flag)
{
	if (m->zero == 1 && m->precision == 0)
	{
		while (*len_buf < m->width)
		{
			ft_bitwise_shift_buf(buf + m->sign, *len_buf, '0');
			(*len_buf)++;
		}
		if (m->plus == 1 && m->sign == 0)
			ft_bitwise_shift_buf(buf, *len_buf, '+');
		if (m->space == 1 && *len_buf < m->width + 1 && m->sign == 0 &&
				m->plus == 0)
			ft_bitwise_shift_buf(buf, *len_buf, ' ');
	}
	else if (m->precision > 0 || m->width > 0)
	{
		if ((m->plus == 1 && m->sign == 0) || (m->space == 1 && m->sign == 0))
			(*len_buf)--;
		while (*len_buf < m->precision)
		{
			ft_bitwise_shift_buf(buf, *len_buf, '0');
			(*len_buf)++;
		}
		ft_ravspom(m, len_buf, buf, flag);
	}
}

static void	ft_begin_init(t_struct *m, int *flag, int *len_buf, char *buf)
{
	if (m->asterisk == 1)
		m->precision = 0;
	*flag = 0;
	if ((m->format[m->i - 1] == '.' ||
				(m->format[m->i - 1] == '0' && m->format[m->i - 2] == '.')))
		*flag = 1;
	if (m->sign == 1 && m->precision >= *len_buf)
	{
		buf[0] = '0';
		m->sign = 2;
	}
	if ((m->plus == 1 && m->sign == 0) || (m->space == 1 && m->sign == 0))
		(*len_buf)++;
	if (m->minus == 1 || *len_buf > m->width)
		ft_la(m, len_buf, buf);
	else if (m->minus == 0 || *len_buf < m->width)
		ft_ra(m, len_buf, buf, flag);
	if (m->sign == 2 && buf[0] != ' ')
		ft_bitwise_shift_buf(buf, *len_buf, '-');
	else if (m->sign == 2)
		buf[0] = '-';
}

void		ft_buf_init_d(char *buf, t_struct *m, int len_buf)
{
	int		flag;

	ft_begin_init(m, &flag, &len_buf, buf);
	if (flag == 1 && m->minus == 0)
	{
		if (buf[len_buf - 1] == '0' && m->width == 0)
			buf[len_buf - 1] = '\0';
		else if (m->width > 0 && m->plus == 0)
			buf[len_buf - 1] = ' ';
		else if (m->width > 0 && m->plus == 1)
			ft_bitwise_shift_buf(buf, len_buf, ' ');
	}
	else if (flag == 1 && m->minus == 1)
	{
		if (buf[0] == '0' && m->width > 0 && m->plus == 0)
			buf[0] = ' ';
		else if (buf[1] == '0' && m->width > 0 && m->plus == 1)
			buf[1] = ' ';
	}
	ft_putstr_fd(buf, m->fd);
	m->len += ft_strlen(buf);
}
