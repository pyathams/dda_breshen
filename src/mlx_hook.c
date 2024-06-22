/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 17:27:05 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/22 20:00:49 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		close_win(vars);
	if (keycode == KEY_R)
		reset_vars(vars);
	if (keycode == KEY_W || keycode == KEY_S
		|| keycode == KEY_A || keycode == KEY_D
		|| keycode == KEY_LEFT || keycode == KEY_RIGHT)
		handle_move(keycode, vars);
	if (keycode == KEY_UP || keycode == KEY_DOWN)
		handle_zoom(keycode, vars);
	if (keycode == KEY_U || keycode == KEY_J || keycode == KEY_I
		|| keycode == KEY_O || keycode == KEY_L || keycode == KEY_K)
		handle_rot(keycode, vars);
	if (keycode == KEY_MINUS || keycode == KEY_PLUS)
		handle_flattening(keycode, vars);
	if (keycode == KEY_P)
	{
		if (vars-> iso)
			vars->iso = 0;
		else
			vars->iso = 1;
	}
	draw(vars);
	return (0);
}
