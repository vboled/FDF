/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:09:03 by gweasley          #+#    #+#             */
/*   Updated: 2020/02/24 12:09:05 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double		get_percent(int max, int min, int current)
{
	double		placement;
	double		range;

	placement = current - min;
	range = max - min;
	return ((range == 0) ? 1.0 : placement / range);
}

int			get_light(int begin, int end, double percent)
{
	return ((1 - percent) * end + percent * begin);
}

int			get_color(int begin, int end, double percent)
{
	int		red;
	int		blue;
	int		green;

	if (begin == end)
		return (begin);
	red = get_light(begin >> 16 & 255, end >> 16 & 255, percent);
	green = get_light(begin >> 8 & 255, end >> 8 & 255, percent);
	blue = get_light(begin & 255, end & 255, percent);
	return ((red << 16) | (green << 8) | blue);
}

void		put_color(t_count *c)
{
	int		i;
	int		j;
	int		a;

	i = -1;
	a = 0;
	if (*c->extr->min < 0)
	{
		a = abs(*c->extr->min);
		*c->extr->min = 0;
		*c->extr->max += a;
	}
	while (++i < c->count_of_str)
	{
		j = -1;
		while (++j < c->count_of_point)
		{
			c->map[i][j].z += a;
			if (!c->map[i][j].color)
				c->map[i][j].color = get_color(0x0000FF, 0xFF0000,
				get_percent(*c->extr->max, *c->extr->min, c->map[i][j].z));
		}
	}
}
