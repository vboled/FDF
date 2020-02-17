/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:32:28 by gweasley          #+#    #+#             */
/*   Updated: 2020/02/17 13:51:53 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point    **map_alloc(int row, int col)
{
    int i;
    int j;
    t_point **map;

    i = 0;
    j = 0;
    if (!(map = (t_point **)malloc(sizeof(t_point *) * row)))
		return (0);
    while (i < row)
	{
		if (!(map[i] = (t_point *)malloc(sizeof(t_point) * col)))
		{
			while (j < i)
			{
				free(map[j]);
				j++;
			}
			free(map);
			return (0);
		}
		i++;
	}
    return (map);
}

void    erase_struct(t_count *c)
{
    c->map = 0;
    c->map_new = 0;
    c->fx = 0;
    c->fy = 0;
    c->fz = 0;
    c->shift_x = 0;
    c->shift_y = 0;
    c->shift_z = 0;
    c->mlx = 0;
    c->win = 0;
}

void    free_map(t_point **map, int row)
{
    int i;

    i = 0;
    if (map)
    {
        while (i < row)
        {
            if (map[i])
                free(map[i]);
            free(map);
            i++;
        }
    }
}

void    free_struct(t_count *c)
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
    if (c->shift_z)
        free(c->shift_z);    
}

int		allocate_mem(t_count *c)
{

    if (!(c->map = map_alloc(c->count_of_str, c->count_of_point)) ||
    !(c->map_new = map_alloc(c->count_of_str, c->count_of_point)))
        return (0);
	if (!(c->fx = (double *)malloc(sizeof(double))) || 
	!(c->fy = (double *)malloc(sizeof(double))) || 
	!(c->fz = (double *)malloc(sizeof(double))) || 
    !(c->shift_x = (int *)malloc(sizeof(int))) ||
    !(c->shift_y = (int *)malloc(sizeof(int))) ||
    !(c->shift_z = (int *)malloc(sizeof(int))))
	{
		return (0);
	}
    *c->fx = 0.0;
    *c->fy = 0.0;
    *c->fz = 0.0;
    *c->shift_x = 0;
    *c->shift_y = 0;
    *c->shift_z = 0;
	return (1);
}
