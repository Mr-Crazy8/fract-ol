#include "fractol.h"

int color_finder(int i, int max_iter)
{
    if (i == max_iter)
        return 0x000000;
    return i * 0x000508;
}

void redraw_fractal(t_fract *fractol)
{
    int x = 0;
    int y = 0;
    int i;
    while (y < 800)
    {
        x = 0;
        while (x < 800)
        {
            if (ft_strcmp(fractol->fracto_name, "mandelbrot") == 0)
                i = mandelbort(x, y, fractol->max_iter, fractol); 
            else if (ft_strcmp(fractol->fracto_name, "julia") == 0)
                i = Julia(x, y, fractol);
           int offset = (y * fractol->size_line) + (x * (fractol->bits_per_pixel / 8));  ////
           *(int *)(fractol->add + offset) = color_finder(i, fractol->max_iter);      /////
                x++;
        }
        y++;
    }
}

int zoom_in(int button, int x, int y, t_fract *win) ////++++
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


int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
        i++;
    return s1[i] - s2[i];
}


void init_mlx(char *argv[], int argc)
{
     t_fract fractol;
    fractol.fracto_name = argv[1];
    fractol.mlx = mlx_init();
    fractol.win = mlx_new_window(fractol.mlx, 800, 800, fractol.fracto_name);
    fractol.img = mlx_new_image(fractol.mlx, 800, 800);
    fractol.add = mlx_get_data_addr(fractol.img, &fractol.bits_per_pixel, &fractol.size_line, &fractol.endian);
    fractol.zoom = 1.0;
    fractol.max_iter = 100;
    if (argc == 4 && (ft_strcmp(argv[1], "julia") == 0)) {
        fractol.xn = ft_atof(argv[2]);
        fractol.yn = ft_atof(argv[3]); }
    redraw_fractal(&fractol);
    mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
    mlx_key_hook(fractol.win, close_wind, NULL);
    mlx_mouse_hook(fractol.win, zoom_in, &fractol);
    mlx_loop(fractol.mlx);

}