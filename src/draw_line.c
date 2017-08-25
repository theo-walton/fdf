/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:47:00 by twalton           #+#    #+#             */
/*   Updated: 2017/08/10 23:47:00 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_info *info, t_coor *coor1, t_coor *coor2)
{
	int x[2];
	int y[2];
	int colour[2];

	x[0] = coor1->x;
	x[1] = coor2->x;
	y[0] = coor1->y;
	y[1] = coor2->y;
	colour[0] = coor1->colour;
	colour[1] = coor2->colour;
	line_draw(x, y, colour, info);
}
