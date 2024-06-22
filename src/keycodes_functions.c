/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 18:39:58 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 18:49:45 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	close_win(t_vars *vars)
{
	free_all(vars);
	exit(EXIT_SUCCESS);
	return ;
}

void	handle_zoom(int keycode, t_vars *vars)
{
	if (keycode == KEY_DOWN)
	{
		if (vars->zoom > 0)
			vars->zoom -= ZOOM_SHIFT;
	}
	if (keycode == KEY_UP)
	{
		if (vars->zoom < (float)INT_MAX)
			vars->zoom += ZOOM_SHIFT;
	}
}

void	handle_move(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
		vars->shift_y += SHIFT;
	if (keycode == KEY_S)
		vars->shift_y -= SHIFT;
	if (keycode == KEY_A || keycode == KEY_RIGHT)
		vars->shift_x += SHIFT;
	if (keycode == KEY_D || keycode == KEY_LEFT)
		vars->shift_x -= SHIFT;
}

void	handle_flattening(int keycode, t_vars *vars)
{
	if (keycode == KEY_PLUS)
	{
		if (vars->flat < 10)
			vars->flat += 0.1;
	}
	if (keycode == KEY_MINUS)
	{
		if (vars->flat > 0)
			vars->flat -= 0.1;
	}
}

void	handle_rot(int keycode, t_vars *vars)
{
	if (keycode == KEY_U)
		vars->rot_x += ROT_SHIFT;
	if (keycode == KEY_J)
		vars->rot_x -= ROT_SHIFT;
	if (keycode == KEY_I)
		vars->rot_y += ROT_SHIFT;
	if (keycode == KEY_K)
		vars->rot_y -= ROT_SHIFT;
	if (keycode == KEY_O)
		vars->rot_z += ROT_SHIFT;
	if (keycode == KEY_L)
		vars->rot_z -= ROT_SHIFT;
}
