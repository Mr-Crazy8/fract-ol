/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:55:50 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/03 13:18:48 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_fract
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*add;
	char	*fracto_name;
	int		max_iter;
	int		color;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	float	scal;
	float	xn;
	float	yn;
	double	zoom;
	double	zx;
	double	zy;
}	t_fract;

int		close_wind(int key, t_fract *fractol);
int		close_wind_x(t_fract *fractol);
int		julia(int x, int y, t_fract *win);
void	init_mlx(char *argv[], int argc);
void	help_mlx(t_fract *fractol);
int		mandelbort(int x, int y, int max_iter, t_fract *win);
int		color_finder(int i, int max_iter);
void	redraw_fractal(t_fract *fractol);
int		zoom_in(int button, int x, int y, t_fract *win);
double	ft_atof(const char *str);
int		ft_strcmp(char *s1, char *s2);

#endif
