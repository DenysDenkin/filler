/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddenkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:49:19 by ddenkin           #+#    #+#             */
/*   Updated: 2018/02/24 20:49:21 by ddenkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

t_map		*init_map(void)
{
	t_map	*res;

	res = (t_map *)malloc(sizeof(t_map));
	res->field = NULL;
	res->pchar = 0;
	res->h = 0;
	res->w = 0;
	return (res);
}

t_token		*init_token(void)
{
	t_token	*res;

	res = (t_token *)malloc(sizeof(t_token));
	res->h = 0;
	res->w = 0;
	res->piece = NULL;
	return (res);
}

void		print_res(t_coord res)
{
	ft_putstr_fd(ft_itoa(res.x), 1);
	write(1, " ", 1);
	ft_putendl_fd(ft_itoa(res.y), 1);
}
