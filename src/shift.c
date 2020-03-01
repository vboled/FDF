/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 14:36:47 by gweasley          #+#    #+#             */
/*   Updated: 2020/02/17 14:36:50 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	centering(t_count *c, int key)
{
	double		step;

	step = 100;
	if (*c->r == 0)
	{
		*c->r = 1000;
		*c->fz = 0.61540309;
		*c->fy = 0.61540309;
		*c->fx = 0.785398;
	}
	else
	{
		if (key == 115)
			*c->r += step;
		else
			*c->r -= step;
	}
}

void	bias(t_count *c)
{
	int i;
	int j;

	i = 0;
	while (i < c->count_of_str)
	{
		j = 0;
		while (j < c->count_of_point)
		{
			c->map_new[i][j].x = c->map_new[i][j].x + *c->shift_x;
			c->map_new[i][j].y = c->map_new[i][j].y + *c->shift_y;
			j++;
		}
		i++;
	}
}

void	shift(t_count *c, int key)
{
	int		shift;

	shift = 10;
	if (key == 123)
		*c->shift_x -= shift;
	if (key == 124)
		*c->shift_x += shift;
	if (key == 125)
		*c->shift_y += shift;
	if (key == 126)
		*c->shift_y -= shift;
}
