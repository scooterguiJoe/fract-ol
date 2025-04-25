/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:28:10 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/25 17:49:49 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/fractol.h"
#include "minilibx-linux/mlx.h"

static void	malloc_error(void)
{
	perror("Problems with malloc");
	exit(EXIT_FAILURE);
}

static void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->interations_def = 42;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
	fractol->zoom = 1.0;
}

static void	events_init(t_fractol *fractol)
{
	mlx_hook(fractol->mlx_window, KeyPress, KeyPressMask, \
	ft_keyhandle, fractol);
	mlx_hook(fractol->mlx_window, ButtonPress, ButtonPressMask, \
	ft_mousehandler, fractol);
	mlx_hook(fractol->mlx_window, DestroyNotify, StructureNotifyMask, \
	ft_closehandler, fractol);
}

void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, \
	WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->image.image_ptr = mlx_new_image(fractol->mlx_connection, \
	WIDTH, HEIGHT);
	if (fractol->image.image_ptr == NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, \
		fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->image.pixel_ptr = mlx_get_data_addr(fractol->image.image_ptr, \
	&fractol->image.bitsppixel, &fractol->image.llen, &fractol->image.endian);
	events_init(fractol);
	data_init(fractol);
}
