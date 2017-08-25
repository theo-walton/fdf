/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 22:12:47 by twalton           #+#    #+#             */
/*   Updated: 2017/08/17 22:12:47 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_release_hooks(int key, t_info *info)
{
	if (key == KEY_W)
		info->keytog->w = 0;
	if (key == KEY_A)
		info->keytog->a = 0;
	if (key == KEY_S)
		info->keytog->s = 0;
	if (key == KEY_D)
		info->keytog->d = 0;
	if (key == KEY_Q)
		info->keytog->q = 0;
	if (key == KEY_E)
		info->keytog->e = 0;
	if (key == KEY_UP)
		info->keytog->up = 0;
	if (key == KEY_DOWN)
		info->keytog->down = 0;
	if (key == KEY_LEFT)
		info->keytog->left = 0;
	if (key == KEY_RIGHT)
		info->keytog->right = 0;
	if (key == KEY_SPACE)
		info->keytog->space = 0;
	return (1);
}
