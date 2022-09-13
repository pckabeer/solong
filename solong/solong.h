/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpanikka <kpanikka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 16:25:29 by kpanikka          #+#    #+#             */
/*   Updated: 2022/09/13 12:29:02 by kpanikka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

typedef struct s_map
{
	int		fd;
	int		width;
	int		height;
	int		len;
	int		isvalid;
	int		count0;
	int		count1;
	int		countc;
	int		counte;
	int		countp;
	int		countm;
	int		ppos ;
	int		mpos ;
	int		mpost ;
	int		pm;
	int		coleat;
	char	*map;
	char	*filename;
	int		img_width;
	int		img_height;
	int		map_width;
	int		map_height;
	void	*mlx;
	void	*win;
	void	*img;
	void	*img1;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*wall;
	char	*floor;
	char	*door;
	char	*coin;
	int		coin_valid;
	char	*player;
	char	*player_s;
	char	*enemy;
	int		temp;
	char	buff;
	int		w;
	int		timer;
}				t_map;

void	init_map(t_map *map);
void	ft_moveplayer(int pos, t_map *map);
int		ft_capture(int key, t_map *map);
int		ft_load_mapdata(t_map *map);
void	ft_checkwall(t_map *map);
void	ft_charvalid(int pos, char buff, t_map *map);
void	ft_isrectangle(t_map *map);
int		ft_isnext_e(int ppos, t_map *map);
int		ft_validpath(int ppos, t_map *map);
void	map_print(t_map *map);
void	ft_create_map(t_map *map);
int		ft_closewin(t_map *map, int fdflag);
void	ft_drawmap(t_map *map);
void	ft_dirhandle(t_map *map);
void	ft_moveenemy(int pos, t_map *map);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);

#endif
