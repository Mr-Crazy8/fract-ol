/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 14:54:57 by anel-men          #+#    #+#             */
/*   Updated: 2025/03/01 15:06:17 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_error(void)
{
	write(2, "Please enter \n\"./fractol mandelbrot\" or \n", 42);
	write(2, "\"./fractol julia [value_1] [value_2]\"\n", 38);
	write(2, "[value_1] and [value_2] must be greater than ", 46);
	write(2, "-2 and less than 2\n", 19);
	exit(1);
}

int	is_valid_number(char *str)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	if (str[j] == '-' || str[j] == '+')
		j++;
	if (str[j] == '.' || str[j] == '\0')
		return (0);
	while (str[j])
	{
		if (str[j] >= '0' && str[j] <= '9')
			j++;
		else if (str[j] == '.')
		{
			j++;
			count++;
			if (count > 1)
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

void	check_dotes(char *argv[])
{
	int	i;

	i = 2;
	while (argv[i])
	{
		if (!is_valid_number(argv[i]))
			print_error();
		i++;
	}
}

void	check_input(char *argv[], int argc)
{
	int	i;
	int	j;

	i = 2;
	j = 0;
	if (argc == 4 && (ft_strcmp(argv[1], "julia") == 0))
	{
		check_dotes(argv);
		if (ft_atof(argv[2]) < -2 || ft_atof(argv[2]) > 2)
			print_error();
		else if (ft_atof(argv[3]) < -2 || ft_atof(argv[3]) > 2)
			print_error();
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (argv[i][j] == ' ')
					print_error();
				j++;
			}
			i++;
		}
	}
}

int	main(int argc, char *argv[])
{
	if ((argc == 2 && (ft_strcmp(argv[1], "mandelbrot") == 0))
		|| (argc == 4 && (ft_strcmp(argv[1], "julia") == 0)))
	{
		check_input(argv, argc);
		init_mlx(argv, argc);
	}
	else
		print_error();
}
