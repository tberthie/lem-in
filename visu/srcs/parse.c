/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:49:53 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/16 23:17:12 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static t_room	*get_room(char **data, t_visu *visu)
{
	t_room	*room;
	char	**split;
	char	type;

	type = (!ft_strcmp(*data, "##start") ? 1 : 0) +
	(!ft_strcmp(*data, "##end") ? 2 : 0);
	while (**data == '#')
		data++;
	room = 0;
	if (ft_parrlen((void**)(split = ft_strsplit(*data, ' '))) == 3)
	{
		room = (t_room*)ft_memalloc(sizeof(t_room));
		room->name = ft_strdup(split[0]);
		room->x = ft_atoi(split[1]);
		room->y = ft_atoi(split[2]);
		room->type = type;
		room->x < visu->limits[0] ? visu->limits[0] = room->x : 0;
		room->x > visu->limits[1] ? visu->limits[1] = room->x : 0;
		room->y < visu->limits[2] ? visu->limits[2] = room->y : 0;
		room->y > visu->limits[3] ? visu->limits[3] = room->y : 0;
	}
	ft_parrfree((void**)split);
	return (room);
}

static void		get_ants(char *amount, t_visu *visu)
{
	int		ants;
	t_ant	*new;

	ants = ft_atoi(amount);
	while (ants--)
		ft_parrpush((void***)&(visu->ants), (new =
		(t_ant*)ft_memalloc(sizeof(t_ant))));
}

t_visu			*parse(t_visu *visu, char **data)
{
	t_room	*room;

	visu->surface = SDL_CreateRGBSurface(0, WINX, WINY, 32, 0, 0, 0, 0);
	visu->rooms = (t_room**)ft_parrnew();
	visu->ants = (t_ant**)ft_parrnew();
	visu->limits[0] = INT_MAX;
	visu->limits[1] = INT_MIN;
	visu->limits[2] = INT_MAX;
	visu->limits[3] = INT_MIN;
	get_ants(*data, visu);
	while ((room = get_room(++data, visu)) || **data == '#')
	{
		while (**data == '#')
			data++;
		room ? ft_parrpush((void***)&visu->rooms, room) : 0;
	}
	while (**data != 'L')
		data++;
	visu->moves = data;
	visu->max_steps = ft_parrlen((void**)data);
	visu->pause = 1;
	return (visu);
}
