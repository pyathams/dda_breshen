/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:59:15 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 18:49:56 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (!distance)
		return (1.0);
	return (placement / distance);
}

int	get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int	get_color(t_point current, t_point start, t_point end, t_point delta)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	r = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF,
			percentage);
	g = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF,
			percentage);
	b = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}

int	get_z_color(t_vars *vars, int cur_z)
{
	double	percentage;

	percentage = percent(vars->map->min_z, vars->map->max_z, cur_z);
	if (percentage < 0.2)
		return (COLOR_1);
	else if (percentage < 0.4)
		return (COLOR_2);
	else if (percentage < 0.6)
		return (COLOR_3);
	else if (percentage < 0.8)
		return (COLOR_4);
	else
		return (COLOR_5);
}
