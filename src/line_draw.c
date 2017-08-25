/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/14 18:51:41 by twalton           #+#    #+#             */
/*   Updated: 2017/08/18 16:22:34 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		swap_ints(int x[], int y[], int colour[])
{
	int temp;

	temp = x[0];
	x[0] = x[1];
	x[1] = temp;
	temp = y[0];
	y[0] = y[1];
	y[1] = temp;
	temp = colour[0];
	colour[0] = colour[1];
	colour[1] = temp;
}

static double	get_gradiant(int x[], int y[])
{
	double grad;
	double a[2];
	double b[2];

	if (x[0] == x[1] && y[0] <= y[1])
		return (INFIN);
	if (x[0] == x[1])
		return (-INFIN);
	a[0] = x[0];
	a[1] = x[1];
	b[0] = y[0];
	b[1] = y[1];
	grad = (b[1] - b[0]) / (a[1] - a[0]);
	return (grad);
}

static void		add_im_data(t_info *info, int x, int y, int colour)
{
	if (x >= info->screen_size[0] || y >= info->screen_size[1])
		return ;
	if (x < 0 || y < 0)
		return ;
	info->image->im[x + y * info->image->line_sz / 4] = colour;
}

static void		add_fun(int *a, char sign1, double *b, char sign2)
{
	if (sign1 == '+')
		*a += 1;
	else
		*a -= 1;
	if (sign2 == '+')
		*b += 1;
	else
		*b -= 1;
}

void			line_draw(int x[], int y[], int colour[], t_info *info)
{
	double gradiant;
	double grad_sum;

	if (x[0] > x[1])
		swap_ints(x, y, colour);
	gradiant = get_gradiant(x, y);
	grad_sum = gradiant;
	colourfun(x, y, colour);
	while (x[0] != x[1] || y[0] != y[1])
	{
		add_im_data(info, x[0] + info->x_shift, y[0] + info->y_shift,
		colourfun(NULL, NULL, NULL));
		if (grad_sum >= 1)
			add_fun(&y[0], '+', &grad_sum, '-');
		else if (grad_sum <= -1)
			add_fun(&y[0], '-', &grad_sum, '+');
		else
		{
			grad_sum += gradiant;
			++x[0];
		}
	}
	colourfun(x, NULL, NULL);
}
