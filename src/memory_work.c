/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:30:31 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/01 12:30:32 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			erase_struct(t_count *c)
{
	c->map = 0;
	c->map_new = 0;
	c->fx = 0;
	c->fy = 0;
	c->fz = 0;
	c->shift_x = 0;
	c->shift_y = 0;
	c->scale = 0;
	c->mlx = 0;
	c->win = 0;
	c->extr = 0;
	c->r = 0;
	c->stretch = 0;
}

void			free_map(t_point **map, int row)
{
	int i;

	i = 0;
	if (map)
	{
		while (i < row)
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		free(map);
	}
}

void			free_struct_1(t_count *c)
{
	if (c->scale)
		free(c->scale);
	if (c->stretch)
		free(c->stretch);
	if (c->r)
		free(c->r);
	if (c->extr)
	{
		if (c->extr->max)
			free(c->extr->max);
		if (c->extr->min)
			free(c->extr->min);
		free(c->extr);
	}
}

void			free_struct(t_count *c)
{
	free_map(c->map, c->count_of_str);
	free_map(c->map_new, c->count_of_str);
	if (c->mlx)
		free(c->mlx);
	if (c->win)
		free(c->win);
	if (c->fx)
		free(c->fx);
	if (c->fy)
		free(c->fy);
	if (c->fz)
		free(c->fz);
	if (c->shift_x)
		free(c->shift_x);
	if (c->shift_y)
		free(c->shift_y);
	free_struct_1(c);
}
