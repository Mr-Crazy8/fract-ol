#include "fractol.h"


void print_error()
{
    write(2, "Please enter \n\t\"./fracto mandelbrot\" or \n\t\"./fractol julia [value_1] [value_2]\"\n" , 81);
    write(2,"[value_1] and [value_2] must be greater than -2 and less than 2\n", 65);
    exit(1);
}

// void check_dotes(char *argv[], int argc)
// {
//     int i = 2;
//     int j = 0;
//     int count = 0;
//     while (argv[i])
//     {
//         j = 0;
//         count = 0;
//         while (argv[i][j])
//         {
       
//             if (argv[i][j] == '-' || argv[i][j] == '+')
//                 j++;
//             if (argv[i][0] == '.' || argv[i][j] == '\0' ||argv[i][j] == '-' || argv[i][j] == '+')
//                 print_error();
//             if (argv[i][j] >= '0' && argv[i][j] <= '9')
//                 j++;
//             else if (argv[i][j] < '0' && argv[i][j] > '9')
//                 print_error();
//             if (argv[i][j] == '.')
//             {
//                 (j++, count++);
//                 if (count > 1)
//                     print_error();
//             }
            
//         }
//         i++;
//     }
// }

void check_input(char *argv[], int argc)
{
    int i = 2;
    int j = 0;
   if (argc == 4 && (ft_strcmp(argv[1], "julia") == 0))
   {
        if (ft_atof(argv[2]) < -2.0 || ft_atof(argv[2]) > 2.0)
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
       // check_dotes(argv, argc);
   }  
}

int main(int argc, char *argv[])
{
   
    if ((argc == 2 && (ft_strcmp(argv[1], "mandelbrot") == 0)) || (argc == 4 && (ft_strcmp(argv[1], "julia") == 0)))
    {
        check_input(argv, argc);
        init_mlx(argv, argc);
    }
    else
        print_error();
}

