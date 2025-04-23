/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:00:53 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/23 17:14:34 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void ft_mypixelput(int x, int y, t_image *image, int color)
{
	int offset;

	offset = (y * image->line_len) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->bits_per_pixel + offset) = color;	
}

void	ft_handlepixel(int x, int y, t_fractol *fractol)
{
	t_complex z;
	t_complex c;
	int i;
	int color;
	
	i = 0;
	z.x = 0.0;
	z.y = 0.0;
	//pixel coordinate x & y 
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);
	while(i < fractol->interations_def)
	{
		z = sum_complex(square_complex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractol->escape_value);
		{
			color = map(i, BLACK, WHITE, 0, fractol->interations_def);
			ft_mypixelput(x, y, &fractol->image, color);
			return ;
		}
		++i;
	}
	ft_mypixelput(x, y, &fractol->image, PSYCHEDELIC_PURPLE);
}

void	ft_fractolrender(t_fractol *fractol)
{
	int x;
	int y;

	y = -1;
	while(++y < HEIGHT)
	{
		x = -1;
		while(++x < WIDTH)
		{
			ft_handlepixel(x, y, fractol);
			
		}
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->image.image_ptr, 0, 0);
}