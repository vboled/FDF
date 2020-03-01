/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 15:09:35 by gweasley          #+#    #+#             */
/*   Updated: 2020/02/17 15:09:36 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		new_x(t_count *c, int i, int j)
{
	return (c->map_new[i][j].x * cos(*c->fy) * cos(*c->fz) + c->map_new[i][j].y
	* sin(*c->fx) * sin(*c->fy) * cos(*c->fz) + c->map_new[i][j].z * cos(*c->fx)
	* sin(*c->fy) * cos(*c->fz) - c->map_new[i][j].y * cos(*c->fx) * sin(*c->fz)
	+ c->map_new[i][j].z * sin(*c->fx) * sin(*c->fz));
}

int		new_y(t_count *c, int i, int j)
{
	return (c->map_new[i][j].x * cos(*c->fy) * sin(*c->fy) + c->map_new[i][j].y
	* sin(*c->fx) * sin(*c->fy) * sin(*c->fz) + c->map_new[i][j].z * cos(*c->fx)
	* sin(*c->fy) * sin(*c->fz) + c->map_new[i][j].y * cos(*c->fx) * cos(*c->fz)
	- c->map_new[i][j].z * sin(*c->fx) * sin(*c->fz));
}

int		new_z(t_count *c, int i, int j)
{
	return (-c->map_new[i][j].x * sin(*c->fy) + c->map_new[i][j].y *
	sin(*c->fx) * cos(*c->fy) + c->map_new[i][j].z * cos(*c->fx) * cos(*c->fy));
}

void	rot(t_count *c)
{
	int i;
	int j;
	int tmp1;
	int tmp2;

	i = 0;
	while (i < c->count_of_str)
	{
		j = 0;
		while (j < c->count_of_point)
		{
			tmp1 = new_z(c, i, j);
			tmp2 = new_x(c, i, j);
			c->map_new[i][j].y = new_y(c, i, j);
			c->map_new[i][j].x = tmp2;
			c->map_new[i][j].z = tmp1;
			j++;
		}
		i++;
	}
}

void	rotation(t_count *c, int key)
{
	double		step;

	step = 0.1;
	if (key == 0)
		*c->fx += step;
	if (key == 6)
		*c->fx -= step;
	if (key == 1)
		*c->fy += step;
	if (key == 7)
		*c->fy -= step;
	if (key == 2)
		*c->fz += step;
	if (key == 8)
		*c->fz -= step;
}
