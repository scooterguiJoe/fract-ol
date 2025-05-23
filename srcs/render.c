/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:00:53 by guvascon          #+#    #+#             */
/*   Updated: 2025/05/11 13:31:27 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	ft_mypixelput(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->llen) + (x * (image->bitsppixel / 8));
	*(unsigned int *)(image->pixel_ptr + offset) = color;
}

static void	mandelbrot_vs_julia(t_complex *z, t_complex *c, t_fractol *fractol)
{
	if (!ft_strncmp(fractol->name, "julia", 5))
	{
		c->x = fractol->julia_x;
		c->y = fractol->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	ft_handlepixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = (map(x, -2, +2, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (map(y, +2, -2, HEIGHT) * fractol->zoom) + fractol->shift_y;
	mandelbrot_vs_julia(&z, &c, fractol);
	while (i < fractol->interations_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = map(i, BLACK, WHITE, fractol->interations_def);
			ft_mypixelput(x, y, &fractol->image, color);
			return ;
		}
		++i;
	}
	ft_mypixelput(x, y, &fractol->image, WHITE);
}

void	ft_fractolrender(t_fractol *fractol)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			ft_handlepixel(x, y, fractol);
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, \
	fractol->mlx_window, fractol->image.image_ptr, 0, 0);
}
