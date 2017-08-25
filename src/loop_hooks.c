/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:30:24 by twalton           #+#    #+#             */
/*   Updated: 2017/08/17 21:30:24 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	are_some_toggles_on(t_keytog *keys)
{
	static unsigned char c;

	if (keys->space)
	{
		if (c++ % 5 != 4)
			return (0);
	}
	if (keys->w || keys->a || keys->s || keys->d || keys->q || keys->e)
		return (1);
	if (keys->up || keys->down || keys->left || keys->right)
		return (1);
	return (0);
}

int			loop_hooks(t_info *info)
{
	if (info->keytog->w)
		rotate_map(info->map, info->map->center, 'x', 1);
	if (info->keytog->a)
		rotate_map(info->map, info->map->center, 'y', 1);
	if (info->keytog->s)
		rotate_map(info->map, info->map->center, 'x', -1);
	if (info->keytog->d)
		rotate_map(info->map, info->map->center, 'y', -1);
	if (info->keytog->e)
		rotate_map(info->map, info->map->center, 'z', -1);
	if (info->keytog->q)
		rotate_map(info->map, info->map->center, 'z', 1);
	if (info->keytog->up)
		info->y_shift -= 2;
	if (info->keytog->down)
		info->y_shift += 2;
	if (info->keytog->left)
		info->x_shift -= 2;
	if (info->keytog->right)
		info->x_shift += 2;
	if (are_some_toggles_on(info->keytog))
		draw_map(info);
	return (1);
}
