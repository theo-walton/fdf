/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colour_based_on_height.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 20:02:04 by twalton           #+#    #+#             */
/*   Updated: 2017/08/13 20:02:04 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	height_to_col2(int height)
{
	if (height >= 6 && height <= 9)
		return (11127953);
	if (height >= 10 && height <= 15)
		return (11128011);
	return (11128063);
}

static int	height_to_col(int height)
{
	if (height <= -5)
		return (2097215);
	if (height == -4)
		return (4259903);
	if (height == -3)
		return (6094911);
	if (height == -2)
		return (8585279);
	if (height == -1)
		return (11075647);
	if (height == 0)
		return (11086139);
	if (height == 1)
		return (11095867);
	if (height == 2)
		return (11104827);
	if (height == 3)
		return (11115835);
	if (height == 4)
		return (11124795);
	if (height == 5)
		return (11127911);
	return (height_to_col2(height));
}

void		set_colour_based_on_height(t_map *map)
{
	int map_size;

	map_size = map->x_dim * map->y_dim;
	while (map_size--)
	{
		if (map->coor[map_size].colour == -1)
			map->coor[map_size].colour = height_to_col(map->coor[map_size].z);
	}
}
