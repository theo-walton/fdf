/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 00:18:25 by twalton           #+#    #+#             */
/*   Updated: 2017/08/18 16:19:51 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		initialize(t_map **new, char *file)
{
	int		i;
	int		fd;
	char	*str;

	i = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &str) > 0)
	{
		normalize_string(str);
		i = ft_chrcount(str, ' ') + 1 + i;
		if (!ft_chrcount(str, ' '))
			return (0);
		free(str);
	}
	close(fd);
	if (!i)
		return (0);
	if (!(*new = malloc(sizeof(t_map))))
		return (0);
	(*new)->x_dim = -1;
	if (!((*new)->coor = malloc(sizeof(t_coor) * i)))
		return (0);
	return (1);
}

static int		get_jth_colour(char *str, int j)
{
	while (j--)
	{
		str = ft_strchr(str, ' ');
		str++;
	}
	while (*str != ' ' && *str != 'x' && *str != '\0')
		++str;
	if (*str == ' ' || *str == '\0')
		return (-1);
	++str;
	return (ft_hextoi(str));
}

static double	get_jth_num(char *str, int j)
{
	while (j--)
	{
		str = ft_strchr(str, ' ');
		str++;
	}
	return ((double)ft_atoi(str));
}

static int		add_info(t_map *new, char *str, int i)
{
	int width;
	int j;

	j = -1;
	if (str == NULL && (new->y_dim = i))
		return (1);
	normalize_string(str);
	width = ft_chrcount(str, ' ') + 1;
	if (new->x_dim == -1)
		new->x_dim = width;
	if (new->x_dim != width)
		return (0);
	while (++j < width)
	{
		if (!is_valid(str, j))
		{
			free(str);
			return (0);
		}
		new->coor[j + i * new->x_dim].z = get_jth_num(str, j);
		new->coor[j + i * new->x_dim].colour = get_jth_colour(str, j);
	}
	free(str);
	return (1);
}

t_map			*get_map(char *file)
{
	int		fd;
	t_map	*new;
	char	*str;
	int		i;

	i = 0;
	if (!initialize(&new, file))
		return (NULL);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	while (get_next_line(fd, &str) > 0)
	{
		if (!ft_strlen(str))
		{
			free(str);
			if (!get_next_line(fd, &str))
				break ;
			free(str);
			return (close_and_ret(NULL, fd));
		}
		if (!add_info(new, str, i++))
			return (close_and_ret(NULL, fd));
	}
	add_info(new, NULL, i);
	return (close_and_ret(new, fd));
}
