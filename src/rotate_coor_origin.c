/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coor_origin.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 20:44:18 by twalton           #+#    #+#             */
/*   Updated: 2017/08/07 20:44:18 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	zrotate_coor(t_coor *a, int rot_amount)
{
	double old1;
	double old2;

	old1 = a->x;
	old2 = a->y;
	if (rot_amount > 0)
	{
		a->x = (ROT_CONST1 * old1 - ROT_CONST2 * old2);
		a->y = (ROT_CONST2 * old1 + ROT_CONST1 * old2);
	}
	else
	{
		a->x = (ROT_CONST1 * old1 + ROT_CONST2 * old2);
		a->y = (-ROT_CONST2 * old1 + ROT_CONST1 * old2);
	}
}

static void	yrotate_coor(t_coor *a, int rot_amount)
{
	double old1;
	double old2;

	old1 = a->x;
	old2 = a->z;
	if (rot_amount > 0)
	{
		a->x = (ROT_CONST1 * old1 - ROT_CONST2 * old2);
		a->z = (ROT_CONST2 * old1 + ROT_CONST1 * old2);
	}
	else
	{
		a->x = (ROT_CONST1 * old1 + ROT_CONST2 * old2);
		a->z = (-ROT_CONST2 * old1 + ROT_CONST1 * old2);
	}
}

static void	xrotate_coor(t_coor *a, int rot_amount)
{
	double old1;
	double old2;

	old1 = a->y;
	old2 = a->z;
	if (rot_amount > 0)
	{
		a->y = (ROT_CONST1 * old1 - ROT_CONST2 * old2) * rot_amount;
		a->z = (ROT_CONST2 * old1 + ROT_CONST1 * old2) * rot_amount;
	}
	else
	{
		a->y = (ROT_CONST1 * old1 + ROT_CONST2 * old2);
		a->z = (-ROT_CONST2 * old1 + ROT_CONST1 * old2);
	}
}

void		rotate_coor_origin(t_coor *coor, char axis, int rot_amount)
{
	if (axis == 'z')
		zrotate_coor(coor, rot_amount);
	else if (axis == 'y')
		yrotate_coor(coor, rot_amount);
	else if (axis == 'x')
		xrotate_coor(coor, rot_amount);
}
