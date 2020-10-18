/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:28:41 by sassassi          #+#    #+#             */
/*   Updated: 2020/08/29 19:12:15 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char				*ft_strjoin_new(char const *s1, char const *s2)
{
	char			*str;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
	{
		str = ft_strnew(ft_strlen(s2));
		ft_strcat(str, s2);
		return (str);
	}
	if (s2 == NULL)
	{
		str = ft_strnew(ft_strlen(s1));
		ft_strcat(str, s1);
		return (str);
	}
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (str == NULL)
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	ft_strdel((char**)&s1);
	return (str);
}

char				*ft_strcut(char *mas, size_t n)
{
	char			*tmp;
	size_t			len;

	if (mas != NULL)
	{
		len = ft_strlen(mas);
		tmp = ft_strnew(len - n);
		ft_strncpy(tmp, mas + n, len - n);
		ft_strdel(&mas);
		mas = tmp;
		if (ft_strlen(mas) == 0 && mas[0] == '\0')
			ft_strdel(&mas);
		return (mas);
	}
	return (NULL);
}

int					ft_remain(char **mas, char **new, char **line)
{
	char			*tmp;
	int				i;

	i = 0;
	tmp = ft_strchr(*mas, 10);
	if (tmp != NULL)
	{
		tmp++;
		i = ft_strlen(*mas) - ft_strlen(tmp);
		*new = ft_strnew(i - 1);
		ft_strncpy(*new, *mas, i - 1);
		*line = *new;
		*mas = ft_strcut(*mas, i);
		return (1);
	}
	*new = ft_strjoin_new(*new, *mas);
	return (2);
}

int					ft_reading(const int *fd, char *c, char **new, char **mas)
{
	int				i;
	int				ret;
	char			*tmp;

	while ((ret = read(*fd, c, BUFF_SIZE)) > 0)
	{
		c[ret] = '\0';
		tmp = ft_strchr(c, 10);
		if (tmp != NULL)
		{
			if (tmp[1] != '\0')
				*mas = ft_strjoin_new(*mas, tmp + 1);
			if (c[0] != '\n')
			{
				i = ft_strlen(tmp + 1);
				tmp = ft_strnew(ret - i - 1);
				ft_strncpy(tmp, c, ret - i - 1);
				*new = ft_strjoin_new(*new, tmp);
				ft_strdel(&tmp);
			}
			break ;
		}
		*new = ft_strjoin_new(*new, c);
	}
	return (ret);
}

int					get_next_line(const int fd, char **line)
{
	static char		*mas[MAS_SIZE];
	char			c[BUFF_SIZE + 1];
	int				ret;
	char			*new;

	new = NULL;
	if (fd < 0 || line == NULL || fd > MAS_SIZE - 1)
		return (-1);
	if (mas[fd])
	{
		if (ft_remain(&mas[fd], &new, line) == 1)
			return (1);
		ft_strdel(&mas[fd]);
	}
	ret = ft_reading(&fd, c, &new, &mas[fd]);
	if (ret == -1)
		return (-1);
	if (ret == 0 && new == NULL)
		return (0);
	if ((BUFF_SIZE == 1 && new == NULL && c[0] == '\n') ||
			(BUFF_SIZE > 0 && new == NULL))
		new = ft_strnew(0);
	*line = new;
	return (1);
}
