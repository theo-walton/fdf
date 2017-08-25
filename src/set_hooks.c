/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 23:15:35 by twalton           #+#    #+#             */
/*   Updated: 2017/08/18 16:21:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	expose(t_info *info)
{
	draw_map(info);
	return (0);
}

static int	exit_hook(void *x)
{
	if (!x)
		exit(1);
	exit(1);
}

void		set_hooks(t_info *info)
{
	mlx_expose_hook(info->win, expose, info);
	mlx_loop_hook(info->mlx, loop_hooks, info);
	mlx_hook(info->win, 2, 0, key_press_hooks, info);
	mlx_hook(info->win, 3, 0, key_release_hooks, info);
	mlx_hook(info->win, 17, 0, exit_hook, NULL);
}
