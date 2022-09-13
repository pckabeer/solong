/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 06:23:27 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/13 12:22:36 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_isnext_e(int ppos, t_map *map)
{
	if (map->map[ppos - map->width] == 'E' || map->map[ppos + 1] == 'E'
		|| map->map[ppos + map->width] == 'E' || map->map[ppos - 1] == 'E')
		return (1);
	return (0);
}

int	ft_validpath(int ppos, t_map *map)
{
	int	res;

	res = 0;
	if (map->map[ppos] == 'C')
		map->coin_valid++;
	map->map[ppos] = 'z';
	if (ft_isnext_e(ppos, map))
		map->isvalid = 1;
	if (map->map[ppos - map->width] != '1' && map->map[ppos - map->width] != 'z'
		&& map->map[ppos - map->width] != 'E')
		res = ft_validpath(ppos - map->width, map);
	if (map->map[ppos + 1] != '1' && map->map[ppos + 1] != 'z'
		&& map->map[ppos + 1] != 'E')
		res = ft_validpath(ppos + 1, map);
	if (map->map[ppos + map->width] != '1' && map->map[ppos + map->width] != 'z'
		&& map->map[ppos + map->width] != 'E')
		res = ft_validpath(ppos + map->width, map);
	if (map->map[ppos - 1] != '1' && map->map[ppos - 1] != 'z'
		&& map->map[ppos - 1] != 'E')
		res = ft_validpath(ppos - 1, map);
	return (res);
}

void	map_print(t_map *map)
{
	write(1, "Moves : ", 8);
	ft_putnbr_fd(map->pm, 1);
	write(1, "\n", 1);
}

void	ft_create_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->filename[i])
		i++;
	if (!(map->filename[--i] == 'r' && map->filename[--i] == 'e' && \
		map->filename[--i] == 'b' && map->filename[--i] == '.'))
		ft_closewin(map, 6);
	map->fd = open(map->filename, O_RDONLY);
	if (map->fd == -1)
		ft_closewin(map, 7);
	ft_isrectangle(map);
	close(map->fd);
	map->map_height = map->img_height * (map->height);
	map->map_width = map->img_width * map->width;
	map->map = malloc(sizeof(char) * map->width * map->height + 1);
	if (!map->map)
		ft_closewin(map, 10);
	ft_load_mapdata(map);
	ft_checkwall(map);
	ft_validpath(map->ppos, map);
	if (!map->isvalid || (map->countc != map->coin_valid))
		ft_closewin(map, 11);
	ft_load_mapdata(map);
}
