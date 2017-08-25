/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map_fit_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 22:18:35 by twalton           #+#    #+#             */
/*   Updated: 2017/08/18 16:21:31 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_max(t_map *map, double max[])
{
	int total_coor;
	int i;

	i = -1;
	total_coor = map->x_dim * map->y_dim;
	max[0] = -9999999999999;
	max[1] = -9999999999999;
	max[2] = -9999999999999;
	while (++i < total_coor)
	{
		if (max[0] < map->coor[i].x)
			max[0] = map->coor[i].x;
		if (max[1] < map->coor[i].y)
			max[1] = map->coor[i].y;
		if (max[2] < map->coor[i].z)
			max[2] = map->coor[i].z;
	}
}

static void		get_min(t_map *map, double min[])
{
	int total_coor;
	int i;

	i = -1;
	total_coor = map->x_dim * map->y_dim;
	min[0] = 9999999999999;
	min[1] = 9999999999999;
	min[2] = 9999999999999;
	while (++i < total_coor)
	{
		if (min[0] > map->coor[i].x)
			min[0] = map->coor[i].x;
		if (min[1] > map->coor[i].y)
			min[1] = map->coor[i].y;
		if (min[2] > map->coor[i].z)
			min[2] = map->coor[i].z;
	}
}

static double	get_translation(t_map *map, int *screen_size)
{
	double max[3];
	double min[3];
	double sf;

	get_max(map, max);
	get_min(map, min);
	sf = screen_size[0] / (max[0] - min[0]);
	if (sf > screen_size[0] / (max[1] - min[1]))
		sf = screen_size[0] / (max[1] - min[1]);
	if (sf > screen_size[0] / (max[2] - min[2]))
		sf = screen_size[0] / (max[2] - min[2]);
	sf = sf * 0.9;
	return (sf);
}

static void		translate(t_coor *shift, t_coor *coor, double sf)
{
	coor->x = coor->x * sf;
	coor->y = coor->y * sf;
	coor->z = coor->z * sf;
	coor->x = coor->x + shift->x;
	coor->y = coor->y + shift->y;
}

void			make_map_fit_screen(int *screen_size, t_map *map)
{
	double	sf;
	int		i;
	int		total_coor;
	t_coor	shift;

	total_coor = map->x_dim * map->y_dim;
	i = -1;
	sf = get_translation(map, screen_size);
	map->center->x = map->center->x * sf;
	map->center->y = map->center->y * sf;
	map->center->z = map->center->z * sf;
	shift.x = screen_size[0] / 2 - map->center->x;
	shift.y = screen_size[1] / 2 - map->center->y;
	while (++i < total_coor)
		translate(&shift, map->coor + i, sf);
	map->center->x = screen_size[0] / 2;
	map->center->y = screen_size[1] / 2;
}
