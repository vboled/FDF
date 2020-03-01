/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 12:45:20 by gweasley          #+#    #+#             */
/*   Updated: 2020/01/03 12:45:25 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <math.h>

int		int_pow(int base, int n)
{
	int i;
	int num;

	if (n == 0)
		return (1);
	i = 1;
	num = base;
	while (i < n)
	{
		base *= num;
		i++;
	}
	return (base);
}

int		hex_atoi(const char *str)
{
	int		num;
	int		i;
	int		res;
	int		j;

	i = 0;
	res = 0;
	if (str[0] != '0' && str[1] != 'x')
		return (-1);
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\n')
		i++;
	j = 1;
	while (str[++j] != '\0' && str[j] != ' ' && str[j] != '\n')
	{
		num = str[j] - '0';
		if (str[j] >= 'A' && str[j] <= 'F')
			num = 10 + str[j] - 'A';
		if (j != 0 && j != 1)
			res += num * int_pow(16, i - j - 1);
	}
	return (res);
}

void	put_in_points(t_point *map, char *line, int k, t_count c)
{
	int		i;

	i = 0;
	while (i < c.count_of_point)
	{
		map->x = 500 * i / c.count_of_point;
		map->y = 500 * k / c.count_of_str;
		map->z = my_atoi(&line);
		if (map->z < *c.extr->min || *c.extr->min == -1)
			*c.extr->min = map->z;
		if (map->z > *c.extr->max)
			*c.extr->max = map->z;
		map->color = 0;
		while (*line && *line != ' ')
		{
			if (*line == ',')
				map->color = hex_atoi(++line);
			line++;
		}
		while (*line == ' ')
			line++;
		map++;
		i++;
	}
}

void	iso(t_count *c)
{
	*c->fz = 0.61540309;
	*c->fy = 0.61540309;
	*c->fx = 0.785398;
	*c->r = 0;
}

void	center(t_count *c)
{
	int		i;
	int		j;
	int		det;

	i = 0;
	if (*c->r != 0)
	{
		while (i < c->count_of_str)
		{
			j = 0;
			det = *c->r + c->map_new[i][j].z;
			while (j < c->count_of_point)
			{
				if (det)
				{
					c->map_new[i][j].x = *c->r * c->map[i][j].x / det;
					c->map_new[i][j].y = *c->r * c->map[i][j].y / det;
				}
				j++;
			}
			i++;
		}
	}
}
