/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_init_float.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:15:54 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/10 17:59:57 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_vspom1(char *buf, int *len_buf, int *len_fp, t_struct *m)
{
	*len_buf = ft_strlen(buf);
	if (*len_fp < m->precisionft)
		while (*len_fp < m->precisionft)
		{
			buf[*len_buf] = '0';
			(*len_buf)++;
			(*len_fp)++;
		}
	else
	{
		while (*len_fp > m->precisionft && m->precisionft != 0)
		{
			buf[*len_buf - 1] = '\0';
			(*len_buf)--;
			(*len_fp)--;
		}
	}
}

static void	ft_vspom3(char *buf, int *len_buf, t_struct *m, char *frac_part)
{
	m->asterisk = 0;
	m->sign = 0;
	if (*len_buf < m->width && m->minus == 1)
	{
		buf[*len_buf] = ' ';
		(*len_buf)++;
	}
	if ((m->conversion == 'g' || m->conversion == 'G') && m->hash == 0)
	{
		while (m->sign < m->precisionft && frac_part[m->sign])
		{
			if (frac_part[m->sign] != '0')
				m->asterisk = 1;
			(m->sign)++;
		}
		if (m->asterisk == 0)
		{
			while (buf[m->asterisk] != '.')
				(m->asterisk)++;
			ft_bzero(buf + m->asterisk, m->precisionft);
		}
		else if (*len_buf > m->precisionft)
			ft_bzero(buf + m->precisionft + 1, *len_buf - m->precisionft);
	}
	m->len += *len_buf;
}

void		ft_buf_init_float(char *int_part, char *frac_part, t_struct *m)
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
	buf = ft_strnew(len_ip + len_fp + m->width + m->precisionft + 1);
	if (buf == NULL)
		return ;
	ft_strcpy(buf, int_part);
	if (m->precisionft != 0)
	{
		buf[len_ip] = '.';
		ft_strcat(buf, frac_part);
	}
	ft_vspom1(buf, &len_buf, &len_fp, m);
	ft_vspomog(buf, &len_buf, m, &flag);
	ft_vspom3(buf, &len_buf, m, frac_part);
	ft_putstr_fd(buf, m->fd);
	ft_strdel(&buf);
}
