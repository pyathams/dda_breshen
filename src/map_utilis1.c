/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilis1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 14:42:48 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 18:49:23 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	get_min_max_z(t_map *map)
{
	int	x;
	int	y;

	y = -1;
	map->max_z = INT_MIN;
	map->min_z = INT_MAX;
	while (++y < map->h)
	{
		x = -1;
		while (++x < map->w)
		{
			if (map->zdir_mt[y][x] < map->min_z)
				map->min_z = map->zdir_mt[y][x];
			else if (map->zdir_mt[y][x] > map->max_z)
				map->max_z = map->zdir_mt[y][x];
		}
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->zdir_mt)
	{
		i = -1;
		while (++i < map->h)
		{
			if (map->zdir_mt[i])
				free(map->zdir_mt[i]);
		}
		free(map->zdir_mt);
	}
	if (map->clrs)
	{
		i = -1;
		while (++i < map->h)
		{
			if (map->clrs[i])
				free(map->clrs[i]);
		}
		free(map->clrs);
	}
	free(map);
}

void	malloc_map(t_map *map)
{
	int	i;

	map->zdir_mt = (int **)malloc(sizeof(int *) * map->h);
	map->clrs = (int **)malloc(sizeof(int *) * map->h);
	if (!map->zdir_mt || !map->clrs)
	{
		free_map(map);
		error_exit();
	}
	i = -1;
	while (++i < map->h)
	{
		map->zdir_mt[i] = (int *)malloc(sizeof(int) * map->w);
		map->clrs[i] = (int *)malloc(sizeof(int) * map->w);
		if (!map->zdir_mt[i] ||!map->clrs[i])
		{
			free_map(map);
			error_exit();
		}
	}
}

int	count_numbers(t_map *map, char *line)
{
	int		count;
	char	**split;

	if (!line)
	{
		free_map(map);
		error_exit();
	}
	split = ft_split(line, ' ');
	if (!split)
	{
		free_map(map);
		error_exit();
	}
	count = 0;
	while (split[count])
	{
		count++;
	}
	free_split(split);
	return (count);
}

t_map	*width_height_map(char *file)
{
	int		fd;
	t_map	*map;
	char	*line;

	map = (t_map *)calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		perror_exit(file);
	map->w = 0;
	map->h = 0;
	line = get_next_line(fd);
	map->w = count_numbers(map, line);
	while (line)
	{
		map->h++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (map);
}
