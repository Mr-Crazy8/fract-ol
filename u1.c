/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:55:09 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/03 15:22:55 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_fractal(t_fract *fractol)
{
	int	x;
	int	y;
	int	i;
	int	offset;

	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			if (ft_strcmp(fractol->fracto_name, "mandelbrot") == 0)
				i = mandelbort(x, y, fractol->max_iter, fractol);
			else if (ft_strcmp(fractol->fracto_name, "julia") == 0)
				i = julia(x, y, fractol);
			offset = (y * fractol->size_line)
				+ (x * (fractol->bits_per_pixel / 8));
			*(int *)(fractol->add
					+ offset) = color_finder(i, fractol->max_iter);
			x++;
		}
		y++;
	}
}

int	zoom_in(int button, int x, int y, t_fract *win)
{
	(void)x;
	(void)y;
	if (button == 4)
		win->zoom *= 1.1;
	else if (button == 5)
		win->zoom *= 0.9;
	redraw_fractal(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img, 0, 0);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (-1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

static void	initialisations(t_fract *fractol, int argc, char *argv[])
{
	fractol->zoom = 1.0;
	fractol->max_iter = 200;
	fractol->zx = 0.0;
	fractol->zy = 0.0;
	if (argc == 4 && (ft_strcmp(fractol->fracto_name, "julia") == 0))
	{
		fractol->xn = ft_atof(argv[2]);
		fractol->yn = ft_atof(argv[3]);
	}
}

void	init_mlx(char *argv[], int argc)
{
	t_fract	fractol;

	fractol.fracto_name = argv[1];
	fractol.mlx = mlx_init();
	if (!fractol.mlx)
		exit(1);
	fractol.win = mlx_new_window(fractol.mlx, 800, 800, fractol.fracto_name);
	if (!fractol.win)
		exit(1);
	fractol.img = mlx_new_image(fractol.mlx, 800, 800);
	if (!fractol.img)
		(mlx_destroy_window(fractol.mlx, fractol.win), exit(1));
	fractol.add = mlx_get_data_addr(fractol.img, &fractol.bits_per_pixel,
			&fractol.size_line, &fractol.endian);
	if (!fractol.add)
	{
		mlx_destroy_image(fractol.mlx, fractol.img);
		(mlx_destroy_window(fractol.mlx, fractol.win), exit(1));
	}
	initialisations(&fractol, argc, argv);
	help_mlx(&fractol);
	mlx_loop(fractol.mlx);
}
