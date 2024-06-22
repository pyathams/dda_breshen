/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:10:13 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 19:22:56 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	args_handle(&map, argc, argv);
	mlx_main(map);
	free_map(map);
	return (0);
}
