/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gweasley <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 08:59:25 by gweasley          #+#    #+#             */
/*   Updated: 2020/01/03 08:59:27 by gweasley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	str_file_count(char *filename, t_count *c)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(filename, O_RDONLY);
	c->count_of_point = -2;
	c->count_of_str = 0;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1 || (ret && !is_suitable(line, (&c->count_of_point))))
		{
			c->count_of_str = -1;
			close(fd);
			return ;
		}
		if (!ret)
		{
			free(line);
			close(fd);
			return ;
		}
		(c->count_of_str)++;
		free(line);
	}
}

int		word_count(char *s, char c)
{
	int i;

	i = 0;
	if (*s == '\0')
		return (1);
	while (*s != '\0')
	{
		while (*s == c)
			++s;
		if (*s != '\0')
		{
			++i;
			while (*s != c && *s != '\0')
				++s;
		}
	}
	if (i == 0)
		return (1);
	return (i);
}

int		is_suitable(char *line, int *num_of_point)
{
	int		num;

	num = word_count(line, ' ');
	if (*num_of_point == -2)
		*num_of_point = num;
	else if (*num_of_point != num)
		return (0);
	while (*line)
	{
		if (!(*line >= '0' && *line <= '9') && *line != ','
		&& *line != ' ' && *line != '\n' && *line != 'x' &&
		*line != '-' && *line != '+' && !(*line >= 'A' && *line <= 'F'))
			return (0);
		line++;
	}
	return (1);
}

int		get_map1(char *filename, t_count *c)
{
	int			i;
	char		*line;
	int			fd;

	if (!allocate_mem(c))
		return (0);
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < c->count_of_str)
	{
		if (get_next_line(fd, &line) == -1)
		{
			close(fd);
			return (0);
		}
		put_in_points(&(*c->map[i]), line, i, *c);
		free(line);
		i++;
	}
	close(fd);
	return (1);
}
