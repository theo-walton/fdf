/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 00:07:17 by twalton           #+#    #+#             */
/*   Updated: 2017/08/07 00:22:44 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	error_out(int x)
{
	if (x == 1)
	{
		ft_putstr_fd("Invalid usage. Enter file name\n", 2);
		exit(1);
	}
	if (x == 2)
	{
		ft_putstr_fd("Error!\n", 2);
		exit(1);
	}
}

static void	add_info_to_info(t_info *info)
{
	info->x_shift = 0;
	info->y_shift = 0;
	if (!(info->image = malloc(sizeof(t_image))))
		error_out(2);
	if (!(info->keytog = ft_memalloc(sizeof(t_keytog))))
		error_out(2);
}

int			main(int ac, char **av)
{
	t_info	info;
	int		screen_size[2];

	info.screen_size = screen_size;
	if (ac != 2)
		error_out(1);
	if (!(info.map = get_map(av[1])))
		error_out(2);
	add_initial_conditions(info.map);
	add_info_to_info(&info);
	get_center(info.map);
	set_colour_based_on_height(info.map);
	get_screen_size(info.map, screen_size);
	make_map_fit_screen(screen_size, info.map);
	info.mlx = mlx_init();
	info.win = mlx_new_window(info.mlx, screen_size[0], screen_size[1], "");
	set_hooks(&info);
	mlx_loop(info.mlx);
}
