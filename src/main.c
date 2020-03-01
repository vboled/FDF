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

int		main(int argc, char **argv)
{
	t_count	c;

	argc++;
	erase_struct(&c);
	c.mlx = mlx_init();
	c.win = mlx_new_window(c.mlx, 1000, 1000, "Window");
	str_file_count(argv[1], &c);
	if (!get_map1(argv[1], &c))
	{
		write(1, "ERROR\n", 6);
		free_struct(&c);
		return (0);
	}
	put_color(&c);
	inverse(&c);
	mlx_key_hook(c.win, deal_hook, &c);
	mlx_loop(c.mlx);
	return (0);
}
