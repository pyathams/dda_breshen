/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utilis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 15:21:32 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 17:38:10 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_vars(t_vars *vars)
{
	if (vars->map)
		free_map(vars->map);
	if (vars->img)
		free(vars->img);
	free(vars->mlx_connection);
	free(vars);
}

void	free_all(t_vars *vars)
{
	mlx_destroy_window(vars->mlx_connection, vars->window);
	mlx_destroy_image(vars->mlx_connection, vars->img->img);
	mlx_destroy_display(vars->mlx_connection);
	free_vars(vars);
}

t_point	new_point(int x, int y, t_vars *vars)
{
	t_point	out;

	out.x = x;
	out.y = y;
	out.z = vars->map->zdir_mt[y][x];
	if (vars->map->iscolor)
		out.color = vars->map->clrs[y][x];
	else
		out.color = get_z_color(vars, out.z);
	return (out);
}

t_point	get_coords(t_vars *vars, t_point point)
{
	point.x *= vars->zoom;
	point.y *= vars->zoom;
	point.z *= (vars->zoom / 10) * vars->flat;
	rot_x(vars, &point.y, &point.z);
	rot_y(vars, &point.x, &point.z);
	rot_z(vars, &point.x, &point.y);
	isometric(vars, &point.x, &point.y, point.z);
	point.x += vars->shift_x;
	point.y += vars->shift_y;
	return (point);
}
