/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/07 20:44:40 by twalton           #+#    #+#             */
/*   Updated: 2017/08/19 21:02:25 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "fdf_structs.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <keys.h>

# define INFIN 9999999999
# define ROT_CONST1 0.99950656036
# define ROT_CONST2 0.03141075907

int		loop_hooks(t_info *info);
int		key_press_hooks(int key, t_info *info);
int		key_release_hooks(int key, t_info *info);
void	normalize_string(char *str);
int		colourfun(int x[], int y[], int colour[]);
void	line_draw(int x[], int y[], int colour[], t_info *info);
void	add_initial_conditions(t_map *map);
void	get_screen_size(t_map *map, int screen_size[]);
void	make_map_fit_screen(int *screen_size, t_map *map);
t_map	*close_and_ret(t_map *map, int fd);
int		draw_map(t_info *info);
void	draw_line(t_info *info, t_coor *coor1, t_coor *coor2);
t_map	*get_map(char *file);
int		is_valid(char *str, int j);
void	set_hooks(t_info *info);
void	set_colour_based_on_height(t_map *map);
void	rotate_map(t_map *map, t_coor *center, char axis, int rot_amount);
void	rotate_coor(t_coor *coor, t_coor *center, char axis, int rot_amount);
void	rotate_coor_origin(t_coor *coor, char axis, int rot_amount);
void	get_center(t_map *map);

#endif
