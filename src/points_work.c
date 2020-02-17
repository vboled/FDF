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

void	print_map(t_count c)///trash
{
	int i = 0;
	int j;

	while (i < 5)
	{
		j = 0;
		while (j < c.count_of_point)
			printf("x = %d ", c.map[i][j++].x);
		printf("\n");
		j = 0;
		while (j < c.count_of_point)
			printf("y = %d ", c.map[i][j++].y);
		printf("\n");
		j = 0;
		while (j < c.count_of_point)
			printf("z = %d ", c.map[i][j++].z);
		printf("\n");
		printf("\n");
		i++;
	}
}

void	put_in_points(t_point *map, char *line, int y, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		map->x = 500 * i / n;
		map->y = y;
		map->z = ft_atoi(line);
		map->color = 0xFFFFFF;
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

void	iso(t_count c)
{
	int i;
	int j;
	int tmp1;
	int tmp2;
	i = 0;
	while (i < c.count_of_str)
	{
		j = 0;
		while (j < c.count_of_point)
		{
			tmp1 = (c.map[i][j].x * sqrt(3) - c.map[i][j].z * sqrt(3)) / sqrt(6);
			tmp2 = c.map[i][j].x / sqrt(6) + 2 * c.map[i][j].y / sqrt(6) + c.map[i][j].z / sqrt(6); 
			c.map[i][j].z = (-c.map[i][j].y * sqrt(2) + c.map[i][j].x * sqrt(2) + c.map[i][j].z * sqrt(2)) / sqrt(6);
			c.map[i][j].x = tmp1;
			c.map[i][j].y = tmp2;
			j++;
		}
		i++;
	}
}