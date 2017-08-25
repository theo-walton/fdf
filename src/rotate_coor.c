/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 21:15:09 by twalton           #+#    #+#             */
/*   Updated: 2017/08/18 16:20:57 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	translate_coor(t_coor *coor, t_coor *center, char sign)
{
	if (sign == '-')
	{
		coor->x -= center->x;
		coor->y -= center->y;
		coor->z -= center->z;
	}
	else
	{
		coor->x += center->x;
		coor->y += center->y;
		coor->z += center->z;
	}
}

void		rotate_coor(t_coor *coor, t_coor *center, char axis, int rot_amount)
{
	translate_coor(coor, center, '-');
	rotate_coor_origin(coor, axis, rot_amount);
	translate_coor(coor, center, '+');
}
