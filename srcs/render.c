/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:00:53 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/23 16:04:29 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	ft_handlepixel(int x, int y, t_fractol *fractol)
{
	t_complex z;
	t_complex c;

	z.x = 0.0;
	z.y = 0.0;

	//pixel coordinate x & y 
	c.x = map(x, -2, +2, 0, WIDTH);
	c.y = map(y, +2, -2, 0, HEIGHT);
	while()
	{
		z = sum_complex(square_complex(z), c);
		if((z.x * z.x) + (z.y * z.y) > fractol->escape_value);
		{
			my_pixel_put();
			return ;
		}
	}
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
			handle_pixel(x, y, fractol);
			
		}
	}
}