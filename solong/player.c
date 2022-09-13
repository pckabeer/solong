/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 22:55:26 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/13 12:27:45 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_moveplayer(int pos, t_map *map)
{
	if (*(map->map + pos) == '0')
	{
		*(map->map + map->ppos) = '0';
		*(map->map + pos) = 'P';
		map->ppos = pos;
		map->pm++;
		ft_drawmap(map);
		map_print(map);
	}
	else if (*(map->map + pos) == 'C')
	{
		*(map->map + map->ppos) = '0';
		*(map->map + pos) = 'P';
		map->ppos = pos;
		map->pm++;
		map->coleat++;
		ft_drawmap(map);
		map_print(map);
	}
	else if (*(map->map + pos) == 'M')
		ft_closewin(map, 0);
	else if (*(map->map + pos) == 'E')
		if (map->countc == map->coleat)
			ft_closewin(map, 0);
}

int	ft_capture(int key, t_map *map)
{
	if (key == 13)
		ft_moveplayer(map->ppos - map->width, map);
	else if (key == 2)
		ft_moveplayer(map->ppos + 1, map);
	else if (key == 0)
		ft_moveplayer(map->ppos - 1, map);
	else if (key == 1)
		ft_moveplayer(map->ppos + map->width, map);
	else if (key == 53)
		ft_closewin(map, 0);
	return (0);
}

void	ft_moveenemy(int pos, t_map *map)
{
	if (*(map->map + pos) == '0')
	{
		*(map->map + map->mpos) = '0';
		*(map->map + pos) = 'M';
		map->mpos = pos;
		ft_drawmap(map);
	}
	else if (*(map->map + pos) == 'P')
	{
		ft_closewin(map, 0);
	}
	else
		map->mpost *= -1;
}

int	ft_closewin(t_map *map, int fdflag)
{
	if (map->fd > 0)
		close(map->fd);
	if (map->map)
		free(map->map);
	if (fdflag == 0)
	{
		write(1, "Game Closing ... \n", 18);
		mlx_destroy_window(map->mlx, map->win);
	}
	if (fdflag == 5)
		write(1, "Error\n Execution format : ./solong <filename.ber>\n", 50);
	else if (fdflag == 6)
		write(1, "Error\nFile extension : <filename.ber> \n", 39);
	else if (fdflag == 7)
		write(1, "Error\n File Error. \n", 20);
	else if (fdflag == 8)
		write(1, "Error\n Invalid Map. \n", 21);
	else if (fdflag == 10)
		write(1, "Error\n Memory allocation error. \n", 33);
	else if (fdflag == 11)
		write(1, "Error\n Invalid Path. No Path available\n", 39);
	exit (1);
	return (0);
}

int	ft_load_mapdata(t_map *map)
{
	int		i;
	int		fd;
	char	buff;

	i = 0;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		ft_closewin(map, 7);
	while (read(fd, &buff, 1))
	{
		if (buff != '\n')
			*(map->map + i++) = buff;
	}
	*(map->map + i++) = '\0';
	close(fd);
	return (1);
}
