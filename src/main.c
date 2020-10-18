/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:25:15 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/18 12:25:11 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

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
//-----------------------------------------------------








int		ft_wordcount(char const *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (s[i] == 0 || (s[i] != c && i == 0))
		counter++;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i - 1] == c)
			counter++;
		i++;
	}
	return (counter);
}
void	ft_getgridsize(fdf *e, char *file)
{
	int		fd;
	char	*line;

	e->width= 0;
	e->height = 0;
	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	e->width = ft_wordcount(line, ' ');
	e->height++;
	
	while (get_next_line(fd, &line) > 0)
	{
		//ft_printf("%s\n", line);
		e->height++;
	}
	free(line);
	close (fd);
}


void fill_map(int *map, char *line, int *colors)//
{
	char **nums;
	int i;

	nums = ft_strsplit(line, ' ');
	i = 0;
	while(nums[i])
	{
		fill_colors(nums[i], &colors[i]);//
		map[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
}

void read_map(fdf *data, char *file)
{
	
	char *line;
	int fd;
	int i;
	
	ft_getgridsize(data, file);

	data->map = (int**)malloc(sizeof(int*) * (data->height + 1));
	data->colors = (int**)malloc(sizeof(int*) * (data->height + 1));//
	i = 0;
	while(i<= data->height)
	{
		data->colors[i] = (int*)malloc(sizeof(int) * (data->width + 1));
		data->map[i++] = (int*)malloc(sizeof(int) * (data->width +1));//
	}
	fd = open(file, O_RDWR);
	i = 0;
	while(get_next_line(fd, &line))
	{
		//ft_printf("%s\n", line);
		fill_map(data->map[i], line, data->colors[i]);//
		free(line);
		i++;
	}
	close (fd);

}
int mod(int i)
{
	return (i < 0) ? -i : i;
}

void isometry(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void draw_line(float x, float y, float x1, float y1, fdf *data)
{
	float x_step;
	float y_step;
	int max;
	int z;
	int z1;

    x += data->shift;
	y += data->shift;
	x1 += data->shift;
	y1 += data->shift;
	z = data->map[(int)y][(int)x];
	z1 = data->map[(int)y1][(int)x1];
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	
	isometry(&x, &y, z);
	isometry(&x1, &y1, z1);
	x_step = x1 - x; // 1 3     2
	y_step = y1 - y; //1 7      6

	
	max = (mod(x_step) > mod(y_step)) ? mod(x_step) : mod (y_step);
	x_step /= max;
	y_step /= max;
	while((int)(x - x1) || (int)(y - y1))
	{
//		mlx_pixel_put(data->mlx, data->win, x, y, 0xffffff);
		x+= x_step;
		y+=y_step;
	}

}


void draw(fdf *data)
{
	int x;
	int y;

	y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x<data->width)
		{
			if(x<data->width -1)
			draw_line(x,y, x+1, y, data);
			if(y<data->height -1)
			draw_line(x,y, x, y+1, data);
			x++;
		}
		y++;
	}
	

}



int hook(int key)
{
	ft_printf("%d", key);
//	if(key == 124)
		//data->shift +=10;
	
	return(0);
}
int			main(int argc, char **argv)
{
	fdf *data;

	data  = (fdf*)malloc(sizeof(fdf));
	read_map(data, argv[1]);
	
	int i;
	i = argc;
/*	int j;
   data->zoom = 10;
	i = argc;
	i = 0;
	data->shift = 1;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_printf("%3d", data->map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1000, 800, "fdf");

	draw(data);
	mlx_key_hook(data->win, hook, NULL);
	mlx_loop(data->mlx);

*/
	return(0);
}