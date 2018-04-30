/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:49:26 by ddenkin           #+#    #+#             */
/*   Updated: 2018/02/24 20:49:27 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void		parse_sizes(char *line, t_map *map)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(line, ' ');
	if (ft_strcmp(tab[0], "Plateau") != 0)
		exit(5);
	map->h = ft_atoi(tab[1]);
	map->w = ft_atoi(tab[2]);
	map->field = (char **)malloc(sizeof(char *) * (map->h + 1));
	i = 0;
	while (i < map->h)
		map->field[i++] = ft_strndup("", (size_t)map->w);
	map->field[i] = 0;
}

void		parse_tsizes(char *line, t_token *token)
{
	char	**tab;
	int		i;

	tab = ft_strsplit(line, ' ');
	token->h = ft_atoi(tab[1]);
	token->w = ft_atoi(tab[2]);
	token->piece = (char **)malloc(sizeof(char *) * (token->h + 1));
	i = 0;
	while (i < token->h)
		token->piece[i++] = ft_strndup("", (size_t)token->w);
	token->piece[i] = 0;
}

int			parse_player(char *line, t_map *map)
{
	char	**tab;

	tab = ft_strsplit(line, ' ');
	if (ft_strcmp(tab[2], "p1") == 0)
		map->pchar = 'o';
	else if (ft_strcmp(tab[2], "p2") == 0)
		map->pchar = 'x';
	else
		return (-1);
	return (1);
}

void		parse_rows(int rows, char **lines, int num)
{
	char	**tab;
	char	*line;
	int		i;

	i = 0;
	while (i < rows)
	{
		get_next_line(0, &line);
		tab = ft_strsplit(line, ' ');
		lines[i] = tab[num];
		i++;
	}
}
