/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 23:21:44 by twalton           #+#    #+#             */
/*   Updated: 2017/08/18 16:19:01 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	redraw(t_info *info)
{
	mlx_clear_window(info->mlx, info->win);
	mlx_put_image_to_window(info->mlx, info->win, info->image->ptr, 0, 0);
	mlx_destroy_image(info->mlx, info->image->ptr);
}

int			draw_map(t_info *info)
{
	int		i;
	int		total_size;
	t_image	*im;

	im = info->image;
	im->ptr = mlx_new_image(info->mlx, info->screen_size[0],
	info->screen_size[1]);
	im->im = (int*)mlx_get_data_addr(im->ptr, &im->bpp, &im->line_sz, &im->end);
	total_size = info->map->x_dim * info->map->y_dim;
	i = -1;
	while (++i < total_size)
		if ((i + 1) % info->map->x_dim)
			draw_line(info, &info->map->coor[i], &info->map->coor[i + 1]);
	i = -1;
	while (++i < total_size)
	{
		if (i < total_size - info->map->x_dim)
		{
			draw_line(info, &info->map->coor[i],
			&info->map->coor[i + info->map->x_dim]);
		}
	}
	redraw(info);
	return (0);
}
