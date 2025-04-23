/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:28:10 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/23 17:17:32 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

static void	malloc_error(void)
{
	printf("Problems with malloc");
	exit(EXIT_FAILURE);
}
void	data_init(t_fractol *fractol)
{
	fractol->escape_value = 4;
	fractol->interations_def = 42;
}
void	fractol_init(t_fractol *fractol)
{
	if (fractol->mlx_connection == NULL)
		malloc_error();
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
	if (fractol->mlx_window == NULL)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->image.image_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if(fractol->image.image_ptr = NULL)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free(fractol->mlx_connection);
		malloc_error();
	}
	fractol->image.pixel_ptr = mlx_get_data_addr(fractol->image.image_ptr, &fractol->image.bits_per_pixel, &fractol->image.line_len, &fractol->image.endian);
	
}
