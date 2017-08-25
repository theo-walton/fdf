/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 01:13:28 by twalton           #+#    #+#             */
/*   Updated: 2017/08/10 01:13:28 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_hexnum(char c)
{
	if (ft_isdigit(c))
		return (1);
	if (c <= 'F' && c >= 'A')
		return (1);
	return (0);
}

static int	num_range(char *str)
{
	if (*str == '\0')
		return (0);
	if (str[0] == '-')
		if (ft_atoi(str) == 0)
			return (0);
	if (str[0] != '-')
		if (ft_atoi(str) == -1)
			return (0);
	return (1);
}

int			is_valid(char *str, int j)
{
	int i;

	i = 0;
	while (j--)
		str = ft_strchr(str, ' ') + 1;
	++j;
	if (!num_range(str))
		return (0);
	if (str[j] == '+' || str[j] == '-')
		++j;
	while (ft_isdigit(str[j]))
		++j;
	if (str[j] == ' ' || str[j] == '\0')
		return (1);
	if (str[j] == ',' && str[j + 1] == 'O' && str[j + 2] == 'x')
	{
		j += 3;
		while (is_hexnum(str[j]) && i++ < 6)
			++j;
		if (str[j] == ' ' && i == 6)
			return (1);
		return (0);
	}
	return (0);
}
