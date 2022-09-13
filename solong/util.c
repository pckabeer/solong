/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:24:23 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/13 12:29:44 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	init_map(t_map *map)
{
	map->fd = 0;
	map->width = 0;
	map->height = 0;
	map->isvalid = 0;
	map->countc = 0;
	map->counte = 0;
	map->countp = 0;
	map->ppos = 0;
	map->mpos = 0;
	map->mpost = 1;
	map->pm = 0;
	map->coleat = 0;
	map->coin_valid = 0;
	map->img_width = 48;
	map->img_height = 48;
	map->wall = "./img/wall.xpm";
	map->floor = "./img/free_tile.xpm";
	map->door = "./img/door.xpm";
	map->coin = "./img/coin.xpm";
	map->player = "./img/knor.xpm";
	map->player_s = "./img/knor_s.xpm";
	map->enemy = "./img/enemy.xpm";
	map->w = 0;
	map->map = NULL;
	map->timer = 0;
}

void	ft_checkwall(t_map *map)
{
	int	i;

	i = 0;
	map->len = map->width * (map->height) - 1;
	while (i < map->width)
	{
		if (map->map[i] != '1' || map->map[map->len - i] != '1')
			ft_closewin(map, 8);
		i++;
	}
	i = 1;
	while (i < map->height)
	{
		if (map->map[i * map->width] != '1'
			|| map->map[map->width * (i + 1) - 1] != '1')
			ft_closewin(map, 8);
		i++;
	}
}

void	ft_charvalid(int pos, char buff, t_map *map)
{
	if (buff == 'C')
		map->countc++;
	else if (buff == 'E')
		map->counte++;
	else if (buff == 'M')
	{
		map->mpos = pos;
		map->countm++;
	}
	else if (buff == 'P')
	{
		map->ppos = pos;
		map->countp++;
	}
	else if (buff != '1' && buff != '0')
		ft_closewin(map, 7);
}

void	ft_dirhandle(t_map *map)
{
	if (map->width)
	{
		if (map->width != map->w)
			ft_closewin(map, 8);
	}
	map->height++;
	if (map->countp != 1 || map->counte != 1 || map->countc <= 0)
		ft_closewin(map, 8);
}

void	ft_isrectangle(t_map *map)
{
	map->temp = read(map->fd, &map->buff, 1);
	while (map->temp)
	{
		if (map->temp < 0)
			ft_closewin(map, 7);
		if (map->buff != '\n')
			ft_charvalid(map->height * map->width + map->w++, map->buff, map);
		else
		{
			if (!map->w)
				ft_closewin(map, 8);
			if (map->width)
			{
				if (map->width != map->w)
					ft_closewin(map, 8);
			}
			else
				map->width = map->w;
			map->height++;
			map->w = 0;
		}
		map->temp = read(map->fd, &map->buff, 1);
	}
	ft_dirhandle(map);
}
