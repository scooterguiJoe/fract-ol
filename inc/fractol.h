/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:51:26 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/23 16:02:19 by guvascon         ###   ########.fr       */
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

#define ERROR_MESSAGE "Please press enter\n"
#define WIDTH 800
#define HEIGHT 800
 
typedef struct s_image
{
	void *image_ptr;
	char *pixel_ptr;
	int bits_per_pixel;
	int endian;
	int line_len;
}	t_image;

typedef struct s_fractol
{
	char *name;
	void *mlx_connection; //mlx_init()
	void *mlx_window; //mlx_new_window()
	t_image image;
	double escape_value; //hipotenusa
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
static void	malloc_error(void);
void	fractol_init(t_fractol *fractol);

//render.c
void	ft_handlepixel(int x, int y, t_fractol *fractol);
void	ft_fractolrender(t_fractol *fractol);

//math_utils
double map(double unscale_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);

#endif