/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guvascon <guvascon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:08:31 by guvascon          #+#    #+#             */
/*   Updated: 2025/04/23 15:54:14 by guvascon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

double map(double unscale_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscale_num - old_min) / (old_max - old_min) + new_min;
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex square_complex(t_complex z)
{
	t_complex result;

	result.x = (z.x * z.x) - (z.x * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
}
