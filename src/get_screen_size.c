/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 21:04:26 by twalton           #+#    #+#             */
/*   Updated: 2017/08/10 21:04:26 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_screen_size(t_map *map, int screen_size[])
{
	int max_dim;

	if (map->x_dim > map->y_dim)
		max_dim = map->x_dim;
	else
		max_dim = map->y_dim;
	screen_size[0] = 200 + sqrt(max_dim) * 50;
	screen_size[1] = screen_size[0];
}
