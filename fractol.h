#ifndef FRACTOL_H
# define FRACTOL_H

#include <mlx.h>
#include  <stdio.h>
#include <stdlib.h>
#include <libc.h>


typedef struct s_fract
{
    void *mlx;
    void *win;
    char *add;
     void *img;
    float scal;
    int max_iter;
    int color;
    double zoom;
    int bits_per_pixel;
    int size_line;
    int endian;
    float xn;
    float yn;
    char *fracto_name;

} t_fract;


int close_wind(int key);  ////+++
int Julia(int x, int y, t_fract *win); 
void init_mlx(char *argv[], int argc);
int mandelbort(int x, int y, int max_iter, t_fract *win);
int color_finder(int i, int max_iter);
void redraw_fractal(t_fract *fractol);
int zoom_in(int button, int x, int y, t_fract *win); ////++++
double	ft_atof(const char *str);
int ft_strcmp(char *s1, char *s2);

#endif
