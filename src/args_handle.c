/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:25:57 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 19:22:38 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	args_handle(t_map **map, int argc, char **argv)
{
	char	*file;

	if (argc != 2)
		error_exit();
	file = argv[1];
	*map = width_height_map(file);
	if (*map == NULL)
		error_exit();
	malloc_map(*map);
	zdir_map(*map, file);
	get_min_max_z(*map);
}
