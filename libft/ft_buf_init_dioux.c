/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf_init_dioux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:53:52 by sassassi          #+#    #+#             */
/*   Updated: 2019/12/05 16:57:47 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buf_init_dioux(char *buf, t_struct *m)
{
	int	len_buf;

	len_buf = ft_strlen(buf);
	if (m->conversion == 'x' || m->conversion == 'X')
		ft_buf_init_x(buf, m, len_buf);
	else if (m->conversion == 'o')
		ft_buf_init_o(buf, m, len_buf);
	else if (m->conversion == 'u' || m->conversion == 'U')
		ft_buf_init_u(buf, m, len_buf);
	else if (m->conversion == 'd' || m->conversion == 'i' ||
			m->conversion == 'D')
		ft_buf_init_d(buf, m, len_buf);
}
