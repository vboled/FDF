/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 10:27:40 by gweasley          #+#    #+#             */
/*   Updated: 2020/01/02 10:27:42 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	test(t_count c) ///
{
	t_point a;
	t_point b;

	int i = 0;
	a.x = 0;
	a.y = 0;
	b.x = 0;
	b.y = 450;
	p_line(c, a, b, 0xFF000);
	b.x = 450;
	b.y = 0;
	p_line(c, a, b, 0xFF000);
	double x = b.x;
	double y = b.y;
	i = 0;
	while (i <= 360)
	{
		double grad = i * 3.14 / 180;
		b.x = x * cos(grad) - y * sin(grad);
		b.y = x * sin(grad) + y * sin(grad);
		p_line(c, a, b, 0xFF0000);
		i += 10;
	}
}

int deal_hook(int key, void *param)
{
	if (key == 53)
	{
		write(1, "EXIT", 4);
		exit (0);
	}
	if ((key >= 0 && key <= 2) || (key >= 6 && key <= 8))
		rotation(param, key);
	if (key >= 123 && key <= 126)
		shift(param, key);
	erase_and_create((t_count *)param);
	rot(param);
	bias(param);
	print_field((t_count *)param);
	return (0);
}


int		main(int argc, char **argv)
{
	t_count	c;
	t_point **map;
	t_point a;
	t_point b;

	erase_struct(&c);
	c.mlx = mlx_init();
	c.win = mlx_new_window(c.mlx, 1000, 1000, "Window");
	str_file_count(argv[1], &c);
	// printf("word c = %d\n", c.count_of_point);
	// printf("str c = %d\n", c.count_of_str);
	if (!get_map1(argv[1], &c))
	{
		write(1, "ERROR\n", 6);
		free_struct(&c);
		return (0);
	}
	*c.fz = 0.61540309;
	*c.fy = 0.61540309;
	*c.fx = 0.785398;
	mlx_key_hook(c.win, deal_hook, &c);
	mlx_loop(c.mlx);
	return (0);
}
