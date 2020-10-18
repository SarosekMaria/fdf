#include "fdf.h"

int     ft_power(int base, int pow)
{
    int res;

    res = 1;
    if (pow == 0)
        return (1);
    if (pow == 1)
        return (base);
    while (pow > 0)
    {
        res *= base;
        pow--;
    }
    return (res);
}

int     ft_atoi_hex(char c)
{
    if (c == 'a' || c == 'A')
        return (10);
    else if (c == 'b' || c == 'B')
        return (11);
    else if (c == 'c' || c == 'C')
        return (12);
    else if (c == 'd' || c == 'D')
        return (13);
    else if (c == 'e' || c == 'E')
        return (14);
    else if (c == 'f' || c == 'F')
        return (15);
    else if (c >= '0' && c <= '9')
        return (c - 48);
    return (0);
}

int		ft_atoi_base(char *str)
{
	int	i;
	int	n;
    int pow;
    int cur_n;

	i = ft_strlen(str) - 1;
	n = 0;
    pow = 0;
	while (i >= 0)
	{
        cur_n = ft_atoi_hex(str[i]);
		n += cur_n * ft_power(16, pow);
        pow++;
		i--;
	}
	return (n);
}


void	fill_colors(char *str, int *color)
{
	char	*hex;
	
	hex = ft_strchr(str, ',');
	if (hex != NULL)
		*color = ft_atoi_base(hex + 1 + 2);// 0x... + 2 == ...
    else
        *color = 0xffffff;
}