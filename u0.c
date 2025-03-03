/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u0.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:55:57 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/03 13:17:36 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	help_mlx(t_fract *fractol)
{
	redraw_fractal(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img, 0, 0);
	mlx_key_hook(fractol->win, close_wind, fractol);
	mlx_mouse_hook(fractol->win, zoom_in, fractol);
	mlx_hook(fractol->win, 17, 0, close_wind_x, fractol);
}

int	close_wind_x(t_fract *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
	return (0);
}

int	close_wind(int key, t_fract *fractol)
{
	if (key == 53)
	{
		mlx_destroy_image(fractol->mlx, fractol->img);
		mlx_destroy_window(fractol->mlx, fractol->win);
		exit(0);
	}
	return (0);
}

int	julia(int x, int y, t_fract *win)
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
	double	temp;

	xn = (-2 + ((((double)x) / 800.0)) * 4) * win->zoom;
	yn = (-2 + ((((double)y) / 800.0)) * 4) * win->zoom;
	i = 0;
	win->zx = 0.0;
	win->zy = 0.0;
	while ((win->zx * win->zx + win->zy * win->zy) < 4 && i < max_iter)
	{
		temp = win->zx * win->zx - win->zy * win->zy + xn;
		win->zy = 2 * win->zx * win->zy + yn;
		win->zx = temp;
		i++;
	}
	return (i);
}
