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

void    bias(t_count *c)
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

void    shift(t_count *c, int key)
{
    int     shift;

    shift = 5;
    if (key == 123)
        *c->shift_x -= shift;
    if (key == 124)
        *c->shift_x += shift;
    if (key == 125)
        *c->shift_y += shift;
    if (key == 126)
        *c->shift_y -= shift;
}
