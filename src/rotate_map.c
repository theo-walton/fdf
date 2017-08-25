/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:29:48 by twalton           #+#    #+#             */
/*   Updated: 2017/08/14 21:29:48 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_map(t_map *map, t_coor *center, char axis, int rot_amount)
{
	int total_coor;
	int i;

	i = 0;
	total_coor = map->x_dim * map->y_dim;
	while (i < total_coor)
	{
		rotate_coor(map->coor + i, center, axis, rot_amount);
		++i;
	}
}
