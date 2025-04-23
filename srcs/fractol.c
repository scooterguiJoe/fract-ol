/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:57:17 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/23 14:00:31 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int main(int ac, char **av)
{
	t_fractol	fractol;
	
	if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) \
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractol.name = av[1];
		fractol_init(&fractol);
		fractol_render(&fractol);
		mlx_loop(fractol.mlx_connection);
	}
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}