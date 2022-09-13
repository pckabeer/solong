/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 08:35:48 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/13 12:28:39 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_timer(t_map *map)
{	
	if (map->timer % 1660 == 0)
	{
		if (map->mpost == 1)
			ft_moveenemy(map->mpos + 1, map);
		else
			ft_moveenemy(map->mpos - 1, map);
	}
	map->timer++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	init_map(&map);
	if (argc != 2)
		ft_closewin(&map, 5);
	map.filename = argv[1];
	ft_create_map(&map);
	map.mlx = mlx_init();
	map.win = mlx_new_window(map.mlx, map.map_width, \
		map.map_height, "Welcome to Knoree");
	ft_drawmap(&map);
	mlx_key_hook(map.win, ft_capture, &map);
	mlx_hook(map.win, 17, 0, ft_closewin, &map);
	mlx_loop_hook(map.mlx, ft_timer, &map);
	mlx_loop(map.mlx);
}
