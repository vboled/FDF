/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_work_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:33:40 by gweasley          #+#    #+#             */
/*   Updated: 2020/03/01 12:33:42 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			init_struct(t_count *c)
{
	*c->fx = 0.0;
	*c->fy = 0.0;
	*c->fz = 0.0;
	*c->shift_x = 0;
	*c->shift_y = 0;
	*c->scale = 1.0;
	*c->stretch = 1.0;
	*c->extr->min = -1;
	*c->extr->max = 0;
	*c->r = 0.0;
}

t_point			**map_alloc(int row, int col)
{
	int			i;
	int			j;
	t_point		**map;

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

int				my_atoi(char **str)
{
	long	number;
	int		sign;

	sign = 1;
	number = 0;
	while (**str == '\t' || **str == ' ' || **str == '\n'
		|| **str == '\v' || **str == '\f' || **str == '\r')
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	while (**str >= '0' && **str <= '9')
	{
		if (number < 0 && number < number * 10)
			return (0);
		if (number > 0 && number > number * 10)
			return (-1);
		number = number * 10 + sign * (**str - '0');
		(*str)++;
	}
	return (number);
}

int				allocate_mem(t_count *c)
{
	if (!(c->map = map_alloc(c->count_of_str, c->count_of_point)) ||
	!(c->map_new = map_alloc(c->count_of_str, c->count_of_point)))
		return (0);
	if (!(c->fx = (double *)malloc(sizeof(double))) ||
	!(c->fy = (double *)malloc(sizeof(double))) ||
	!(c->fz = (double *)malloc(sizeof(double))) ||
	!(c->shift_x = (int *)malloc(sizeof(int))) ||
	!(c->shift_y = (int *)malloc(sizeof(int))) ||
	!(c->scale = (double *)malloc(sizeof(double))) ||
	!(c->extr = (t_min_max *)malloc(sizeof(t_min_max))) ||
	!(c->extr->min = (int *)malloc(sizeof(int))) ||
	!(c->extr->max = (int *)malloc(sizeof(int))) ||
	!(c->stretch = (double *)malloc(sizeof(double))) ||
	!(c->r = (double *)malloc(sizeof(double))))
		return (0);
	init_struct(c);
	return (1);
}
