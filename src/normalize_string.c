/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 15:03:31 by twalton           #+#    #+#             */
/*   Updated: 2017/08/17 15:03:31 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	normalize_string(char *str)
{
	int i;

	i = 0;
	ft_replacewhitespace(str, ' ');
	if (*str == ' ')
		ft_memmove(str, str + 1, ft_strlen(str));
	while (str[i])
		++i;
	if (str[i - 1] == ' ')
		str[i - 1] = '\0';
}
