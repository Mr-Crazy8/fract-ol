#include "fractol.h"

static int	skip_whitespace_and_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
	}
	return (i);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	double	result;
	double	decimal_place;

	sign = 1;
	result = 0.0;
	decimal_place = 0.1;
	i = skip_whitespace_and_sign(str, &sign);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i++] == '.')
	{
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') * decimal_place;
			decimal_place *= 0.1;
			i++;
		}
	}
	return (result * sign);
}

int	close_wind(int key)
{
	if (key == 53)
		exit(0);
	return (0);
}

int	Julia(int x, int y, t_fract *win)
{
	int		i;
	double	zx;
	double	zy;
	double	temp;

	i = 0;
	zx = ((double)x / 800.0) * 4 - 2;
	zy = ((double)y / 800.0) * 4 - 2;
	zx = win->zoom * zx;
	zy = win->zoom * zy;
	while ((zx * zx + zy * zy) < 4 && i < win->max_iter)
	{
		temp = zx * zx - zy * zy + win->xn;
		zy = 2 * zx * zy + win->yn;
		zx = temp;
		i++;
	}
	return (i);
}

int	mandelbort(int x, int y, int max_iter, t_fract *win)
{
	int		i;
	double	xn;
	double	yn;
	double	zx;
	double	zy;
	double	temp;

	xn = (-2 + ((((double)x) / 800.0)) * 4) * win->zoom;
	yn = (-2 + ((((double)y) / 800.0)) * 4) * win->zoom;
	i = 0;
	zx = 0.0;
	zy = 0.0;
	while ((zx * zx + zy * zy) < 4 && i < max_iter)
	{
		temp = zx * zx - zy * zy + xn;
		zy = 2 * zx * zy + yn;
		zx = temp;
		i++;
	}
	return (i);
}
