/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:49:04 by ddenkin           #+#    #+#             */
/*   Updated: 2018/02/24 20:49:06 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int					token_fits(t_map *map, t_token *token, t_coord c)
{
	t_coord	iter;
	int		covers;
	int		h[2];

	covers = 0;
	iter.x = -1;
	while (++iter.x < token->h)
	{
		iter.y = -1;
		while (++iter.y < token->w)
		{
			if (token->piece[iter.x][iter.y] != '*')
				continue ;
			if ((c.x + iter.x < 0 || c.y + iter.y < 0 || c.x + iter.x >= map->h\
		|| c.y + iter.y > map->w) && token->piece[iter.x][iter.y] == '*')
				return (-1);
			h[0] = ft_tolower(map->field[c.x + iter.x][c.y + iter.y]);
			h[1] = ft_tolower(token->piece[iter.x][iter.y]);
			if (h[0] == map->pchar && c.y + iter.y < map->w && h[1] == '*')
				covers++;
			if (h[0] != map->pchar && h[0] != '.' && h[0] != 0 && h[1] == '*')
				return (-1);
		}
	}
	return (covers);
}

double				min_token_distance(t_map *map, t_coord tc,
																t_coord enc)
{
	int		i;
	double	min;
	double	tmp;

	i = 0;
	min = map->w * map->h;
	tmp = ft_sqrt(ft_pow(tc.x - enc.x, 2) + ft_pow(tc.y - enc.y, 2));
	if (tmp < min)
		min = tmp;
	return (min);
}

double				find_distance(t_map *map, t_coord c)
{
	t_coord iter;
	double	wat;
	double	wtemp;

	iter.x = 0;
	wat = map->h * map->w;
	while (iter.x < map->h)
	{
		iter.y = 0;
		while (iter.y < map->w + 1)
		{
			if (map->field[iter.x][iter.y] != '.' && map->field[iter.x][iter.y]
				!= 0 && ft_tolower(map->field[iter.x][iter.y]) != map->pchar)
			{
				wtemp = min_token_distance(map, c, iter);
				if (wtemp < wat)
					wat = wtemp;
			}
			iter.y++;
		}
		iter.x++;
	}
	return (wat);
}

void				calculate_coords(t_map *map, t_token *token)
{
	t_coord		iter;
	t_coord		res;
	double		d;
	double		distance;

	iter.x = -map->h;
	res.x = 100;
	res.y = 100;
	d = (map->h + token->h) * (map->w + token->w);
	while (++iter.x < map->h)
	{
		iter.y = -map->w;
		while (++iter.y < map->w)
		{
			if (token_fits(map, token, iter) == 1)
				if ((distance = find_distance(map, iter)) < d)
				{
					res.x = iter.x;
					res.y = iter.y;
					d = distance;
				}
		}
		if (iter.x == map->h - 1)
			print_res(res);
	}
}

void				print_map(t_map *map)
{
	int 	fd;

	fd = open("out.txt", O_CREAT | O_WRONLY | O_APPEND);
	for (int i = 0; i < map->h; i++)
		ft_putendl_fd(map->field[i], fd);
	close(fd);
}

int					main(void)
{
	t_map	*map;
	t_token	*token;
	char	*stuff;

	map = init_map();
	token = init_token();
	get_next_line(0, &stuff);
	if (parse_player(stuff, map) == -1)
		return (-1);
	while (1)
	{
		if (get_next_line(0, &stuff) == 0 || stuff[0] == '=')
			break ;
		parse_sizes(stuff, map);
		get_next_line(0, &stuff);
		parse_rows(map->h, map->field, 1);
		get_next_line(0, &stuff);
		parse_tsizes(stuff, token);
		parse_rows(token->h, token->piece, 0);
		print_map(map);
		calculate_coords(map, token);
	}
	return (0);
}
