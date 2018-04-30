/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:48:50 by ddenkin           #+#    #+#             */
/*   Updated: 2018/02/24 20:48:51 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"

typedef struct		s_map
{
	char			pchar;
	int				w;
	int				h;
	char			**field;
}					t_map;

typedef struct		s_token
{
	int				w;
	int				h;
	char			**piece;
}					t_token;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;
t_map				*init_map();
t_token				*init_token();
void				parse_sizes(char *line, t_map *map);
void				parse_tsizes(char *line, t_token *token);
int					parse_player(char *line, t_map *map);
void				parse_rows(int rows, char **lines, int num);
void				print_res(t_coord res);
#endif
