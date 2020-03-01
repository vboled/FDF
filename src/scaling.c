/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stretching.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:30:38 by gweasley          #+#    #+#             */
/*   Updated: 2020/02/18 10:41:18 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scaling(t_count *c, int key)
{
	double	step;

	step = 0.5;
	if (key == 69 || key == 4)
		*c->scale += step;
	else
		*c->scale -= step;
	if (*c->scale < 0)
		*c->scale = 1;
}

void	scale(t_count *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < c->count_of_str)
	{
		j = 0;
		while (j < c->count_of_point)
		{
			c->map_new[i][j].x *= *c->scale;
			c->map_new[i][j].y *= *c->scale;
			c->map_new[i][j].z *= *c->scale;
			j++;
		}
		i++;
	}
}

void	inverse(t_count *c)
{
	int	i;
	int	j;

	i = 0;
	while (i < c->count_of_str)
	{
		j = 0;
		while (j < c->count_of_point)
		{
			c->map[i][j].z = *c->extr->max - c->map[i][j].z + *c->extr->min;
			j++;
		}
		i++;
	}
}

void	stretching(t_count *c, int key)
{
	double	step;

	step = 0.5;
	if (key == 116)
		*c->stretch += step;
	else
		*c->stretch -= step;
}

void	stretch(t_count *c)
{
	int		i;
	int		j;

	i = 0;
	while (i < c->count_of_str)
	{
		j = 0;
		while (j < c->count_of_point)
		{
			c->map_new[i][j].z = c->map[i][j].z * *c->stretch;
			c->map_new[i][j].x = c->map[i][j].x;
			c->map_new[i][j].y = c->map[i][j].y;
			c->map_new[i][j].color = c->map[i][j].color;
			j++;
		}
		i++;
	}
}
