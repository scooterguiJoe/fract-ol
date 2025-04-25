/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 17:13:47 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/25 17:29:54 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"
#include "minilibx-linux/mlx.h"

int	ft_closehandler(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->image.image_ptr);
	mlx_clear_window(fractol->mlx_connection, fractol->mlx_window);
	mlx_destroy_display(fractol->mlx_connection);
	free(fractol->mlx_connection);
	exit(EXIT_SUCCESS);
}
int ft_keyhandle(int keysym, t_fractol *fractol)
{
	if(keysym == XK_Escape)
		ft_closehandler(fractol);
	else if(keysym == XK_Right)
		fractol->shift_x -= (0.5 * fractol->zoom);
	else if(keysym == XK_Left)
		fractol->shift_x += (0.5 * fractol->zoom);
	else if(keysym == XK_Up)
		fractol->shift_y -= (0.5 * fractol->zoom);
	else if(keysym == XK_Down)
		fractol->shift_y += (0.5 * fractol->zoom);
	else if(keysym == XK_plus)
		fractol->interations_def += 10;
	else if(keysym == XK_minus)
		fractol->interations_def -= 10;
	ft_fractolrender(fractol);
	return 0;
}

int ft_mousehandler(int buttom, int x, int y, t_fractol *fractol)
{
	//zoom in
	if(buttom == Button5)
	{
		fractol->zoom *= 0.95;
	}
	//zoom out
	else if(buttom == Button4)
	{
		fractol->zoom *= 1.05;
	}
	//refresh
	ft_fractolrender(fractol);
	return 0;
}