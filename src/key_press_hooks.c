/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 21:04:53 by twalton           #+#    #+#             */
/*   Updated: 2017/08/17 21:04:53 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_press_hooks(int key, t_info *info)
{
	if (key == KEY_W)
		info->keytog->w = 1;
	if (key == KEY_A)
		info->keytog->a = 1;
	if (key == KEY_S)
		info->keytog->s = 1;
	if (key == KEY_D)
		info->keytog->d = 1;
	if (key == KEY_Q)
		info->keytog->q = 1;
	if (key == KEY_E)
		info->keytog->e = 1;
	if (key == KEY_UP)
		info->keytog->up = 1;
	if (key == KEY_DOWN)
		info->keytog->down = 1;
	if (key == KEY_LEFT)
		info->keytog->left = 1;
	if (key == KEY_RIGHT)
		info->keytog->right = 1;
	if (key == KEY_SPACE)
		info->keytog->space = 1;
	if (key == KEY_ESC)
		exit(1);
	return (1);
}
