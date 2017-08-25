/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved_colour_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 10:17:28 by twalton           #+#    #+#             */
/*   Updated: 2017/08/17 10:17:28 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_arrays(double colour_vector[], double current[], int colour[])
{
	int c1;
	int c2;

	c1 = colour[0];
	c2 = colour[1];
	colour_vector[0] = c2 % 256 - c1 % 256;
	current[0] = c1 % 256;
	c1 /= 256;
	c2 /= 256;
	colour_vector[1] = c2 % 256 - c1 % 256;
	current[1] = c1 % 256;
	c1 /= 256;
	c2 /= 256;
	colour_vector[2] = c2 % 256 - c1 % 256;
	current[2] = c1 % 256;
}

static void	scale_colour_vector(double colour_vector[], int x[], int y[])
{
	int total_pixels;

	total_pixels = abs(x[0] - x[1]) + abs(y[0] - y[1]);
	if (!total_pixels)
		return ;
	colour_vector[0] /= total_pixels;
	colour_vector[1] /= total_pixels;
	colour_vector[2] /= total_pixels;
}

static void	colour_vector_to_current(double curr[], double vector[], char sign)
{
	if (sign == '+')
	{
		curr[0] += vector[0];
		curr[1] += vector[1];
		curr[2] += vector[2];
	}
	else
	{
		curr[0] -= vector[0];
		curr[1] -= vector[1];
		curr[2] -= vector[2];
	}
}

static int	get_colour(double curr[])
{
	int colour;

	colour = (int)curr[0] + (int)curr[1] * 256 + (int)curr[2] * 256 * 256;
	return (colour);
}

int			colourfun(int x[], int y[], int colour[])
{
	static double	colour_vector[3];
	static int		toggle;
	static double	current[3];

	if (!toggle)
	{
		get_arrays(colour_vector, current, colour);
		scale_colour_vector(colour_vector, x, y);
		colour_vector_to_current(current, colour_vector, '-');
		toggle = 1;
		return (0);
	}
	if (!x)
	{
		colour_vector_to_current(current, colour_vector, '+');
		return (get_colour(current));
	}
	toggle = 0;
	return (0);
}
