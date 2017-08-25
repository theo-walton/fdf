/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 01:16:48 by twalton           #+#    #+#             */
/*   Updated: 2017/08/19 21:01:17 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H

typedef struct	s_coor
{
	double		x;
	double		y;
	double		z;
	int			colour;
}				t_coor;

typedef struct	s_image
{
	void		*ptr;
	int			*im;
	int			bpp;
	int			line_sz;
	int			end;
}				t_image;

typedef struct	s_map
{
	int			x_dim;
	int			y_dim;
	t_coor		*coor;
	t_coor		*center;
}				t_map;

typedef struct	s_keytog
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			q;
	int			e;
	int			up;
	int			down;
	int			left;
	int			right;
	int			space;
}				t_keytog;

typedef struct	s_info
{
	t_map		*map;
	int			x_shift;
	int			y_shift;
	void		*mlx;
	void		*win;
	int			*screen_size;
	t_image		*image;
	t_keytog	*keytog;
}				t_info;

#endif
