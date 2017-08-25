/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_center.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:44:01 by twalton           #+#    #+#             */
/*   Updated: 2017/08/18 16:18:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	av_heights(t_map *map)
{
	int		i;
	int		total_dims;
	double	sum;

	total_dims = map->x_dim * map->y_dim;
	i = 0;
	sum = 0;
	while (i < total_dims)
		sum += map->coor[i++].z;
	return (sum / total_dims);
}

void			get_center(t_map *map)
{
	if (!(map->center = malloc(sizeof(t_coor))))
	{
		write(2, "Error!", 6);
		exit(1);
	}
	map->center->x = (map->x_dim - 1) / 2.0;
	map->center->y = (map->y_dim - 1) / 2.0;
	map->center->z = av_heights(map);
}
