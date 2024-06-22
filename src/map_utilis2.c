/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utilis2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyathams <pyathams@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:14:36 by pyathams          #+#    #+#             */
/*   Updated: 2024/06/20 17:37:54 by pyathams         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (!s || !f)
		return ;
	while (*s)
		f(s++);
}

void	char_tolower(char *c)
{
	*c = ft_tolower(*c);
}

int	color_line(t_map *map, char *s)
{
	int	result;

	while (*s && (ft_isdigit(*s) || *s == '-' || *s == '+' || *s == ',' ))
		s++;
	if (*s && *s == 'x')
	{
		map->iscolor = 1;
		ft_striter(s + 1, char_tolower);
		result = ft_atoi_base(s + 1, LHEX);
		return (result);
	}
	else
		return (WHITE);
	return (0);
}

void	filling_zdir(t_map *map, int fd)
{
	int		x;
	int		y;
	char	*line;
	char	**split;

	y = -1;
	while (++y < map ->h)
	{
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		if (!split)
		{
			free_map(map);
			error_exit();
		}
		x = -1;
		while (++x < map->w)
		{
			map->zdir_mt[y][x] = ft_atoi(split[x]);
			map->clrs[y][x] = color_line(map, split[x]);
		}
		free_split(split);
		free(line);
	}
}

void	zdir_map(t_map *map, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		free_map(map);
		perror_exit(file);
	}
	filling_zdir(map, fd);
	close(fd);
}
