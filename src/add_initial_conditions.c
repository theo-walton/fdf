/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_initial_conditions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:39:08 by twalton           #+#    #+#             */
/*   Updated: 2017/08/10 21:39:08 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_initial_conditions(t_map *map)
{
	int i;
	int total_coor;

	total_coor = map->x_dim * map->y_dim;
	i = -1;
	while (++i < total_coor)
	{
		map->coor[i].x = i % map->x_dim;
		map->coor[i].y = i / map->x_dim;
	}
}
