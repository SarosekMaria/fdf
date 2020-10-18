/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sassassi <sassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 14:18:37 by sassassi          #+#    #+#             */
/*   Updated: 2020/10/18 12:23:41 by sassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "ft_printf.h"
# include "libft.h"
//# include "mlx.h"
# define BUFF_SIZE 1
# define MAS_SIZE 12000
# define MAX_INT 2147483647





typedef struct
{
	int width;
	int height;
	int **map;
	int	**colors;
	int zoom;
	int shift;
	void		*mlx;
	void		*win;

} fdf;

void	fill_colors(char *str, int *color);

#endif

//comments:
//func ft_getgridsize:
//		while (get_next_line(fd, &line) > 0)
//		{
//			e->height++;
//			free(line);??
//		}