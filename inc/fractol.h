/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:51:26 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/25 17:49:07 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <unistd.h>

#define ERROR_MESSAGE "Please press enter\n \n\t\"./fractol mandelbrot\" or \n\t\"./fractol julia <value_1> <value_2>\"\n"
#define WIDTH 800
#define HEIGHT 800
 
#define BLACK       0x000000
#define WHITE       0xFFFFFF
#define RED         0xFF0000
#define GREEN       0x00FF00
#define BLUE        0x0000FF

#define MAGENTA_BURST   0xFF00FF
#define LIME_SHOCK      0xCCFF00
#define NEON_ORANGE     0xFF6600
#define PSYCHEDELIC_PURPLE 0x660066 
#define AQUA_DREAM      0x33CCCC  
#define HOT_PINK        0xFF66B2  
#define ELECTRIC_BLUE   0x0066FF  
#define LAVA_RED        0xFF3300  

typedef struct s_image
{
	void *image_ptr;
	char *pixel_ptr;
	int bitsppixel;
	int endian;
	int llen;
}	t_image;

typedef struct s_fractol
{
	char *name;
	void *mlx_connection; //mlx_init()
	void *mlx_window; //mlx_new_window()
	t_image image;
	double escape_value; //hipotenusa
	int interations_def; //image quality and rendering speed
	double shift_x;
	double shift_y;
	double zoom;
}	t_fractol;

typedef struct s_complex
{
	double x;
	double y;
}	t_complex;


//string_utils.c
int	ft_strncmp(char *s1, char *s2, int n);
void ft_putstr_fd(char *s, int fd);

//init.c
// void	malloc_error(void);
// void	data_init(t_fractol *fractol);
void	fractol_init(t_fractol *fractol);
//static void events_init(t_fractol *fractol);

//render.c
// void ft_mypixelput(int x, int y, t_image *image, int color);
// void	ft_handlepixel(int x, int y, t_fractol *fractol);
void	ft_fractolrender(t_fractol *fractol);

//math_utils
double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

//events.c
int	ft_closehandler(t_fractol *fractol);
int ft_keyhandle(int keysym, t_fractol *fractol);
int ft_mousehandler(int buttom, int x, int y, t_fractol *fractol);

#endif