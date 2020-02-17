/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 13:08:30 by gweasley          #+#    #+#             */
/*   Updated: 2020/02/02 13:08:32 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_line1(t_count c, t_point a, t_line l, int color)
{
	int d;
	int d1;
	int d2;
	int i;

	mlx_pixel_put(c.mlx, c.win, a.x, a.y, color);
	a.x += l.sx;
	i = 1;
	d = (l.dy << 1) - l.dx;
	d1 = l.dy << 1;
	d2 = (l.dy - l.dx) << 1;
	while (i < l.dx)
	{
		if (d > 0)
		{
			d += d2;
			a.y += l.sy;
		}
		else
			d += d1;
		mlx_pixel_put(c.mlx, c.win, a.x, a.y, color);
		a.x += l.sx;
		i++;
	}
}

void	put_line2(t_count c, t_point a, t_line l, int color)
{
	int d;
	int d1;
	int d2;
	int i;

	d = (l.dx << 1) - l.dy;
	d1 = l.dx << 1;
	d2 = (l.dx - l.dy) << 1;
	mlx_pixel_put(c.mlx, c.win, a.x, a.y, color);
	a.y += l.sy;
	i = 1;
	while (i <= l.dy)
	{
		if (d > 0)
		{
			d += d2;
			a.x += l.sx;
		}
		else
			d += d1;
		mlx_pixel_put(c.mlx, c.win, a.x, a.y, color);
		a.y += l.sy;
		i++;
	}
}

void	p_line(t_count c, t_point a, t_point b, int color)
{
	t_line l;

	a.x += 300;
	b.x += 300;
	a.y += 500;
	b.y += 500;
	l.dx = (b.x > a.x) ? (b.x - a.x) : (a.x - b.x);
	l.dy = (b.y > a.y) ? (b.y - a.y) : (a.y - b.y);
	l.sx = (b.x >= a.x) ? (1) : (-1);
	l.sy = (b.y >= a.y) ? (1) : (-1);
	if (l.dy < l.dx)
		put_line1(c, a, l, color);
	else
		put_line2(c, a, l, color);
}

void	print_work_space(t_count c)
{
	t_point		a;
	t_point		b;

	a.x = 200;
	a.y = 0;
	b.x = 697;
	b.y = 0;
	p_line(c, a, b, 0xFFFFFF);
	b.y = 497;
	b.x = 200;
	p_line(c, a, b, 0xFFFFFF);
	a.x = 697;
	a.y = 497;
	b.x = 697;
	b.y = 0;
	p_line(c, a, b, 0xFFFFFF);
	b.x = 200;
	b.y = 497;
	p_line(c, a, b, 0xFFFFFF);
}

void	print_field(t_count* c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	p_line(*c, (c->map_new)[0][0], (c->map_new)[0][c->count_of_point - 1], 0xd9701a); // orange
	while (i < c->count_of_str - 1)
	{
		j = 0;
		while (j < c->count_of_point - 1)
		{		
			p_line(*c, c->map_new[i][j], c->map_new[i + 1][j], 0xd9701a); // orange
			p_line(*c, c->map_new[i][j], c->map_new[i][j + 1], 0xd9701a); // white
			j++;
		}
		p_line(*c, c->map_new[i][j], c->map_new[i + 1][j], 0xd9701a); // turquoise
		i++;
	}
	j = 0;
	while (j < c->count_of_point - 1)
	{		
		p_line(*c, c->map_new[i][j], c->map_new[i][j + 1], 0xd9701a); // white
		j++;
	}
}
