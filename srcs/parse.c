/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:47:36 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/10 16:25:05 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

#include <stdlib.h>

static char		check_parsing(t_lemin *lemin)
{
	if (!lemin->start || !lemin->end)
		return (0);
	return (1);
}

static char		parse_links(t_lemin *lemin, char **lines)
{
	while (*lines)
	{
		lines++;
	}
	return (check_parsing(lemin));
}

static char		parse_rooms(t_lemin *lemin, char **lines)
{
	t_room		*room;
	char		**split;

	while (*lines && !((*lines)[ft_intlen(ft_atoi(*lines))] == '-'))
	{
		if (ft_parrlen((void**)(split = ft_strsplit(*lines, ' '))) != 3)
			return (0);
		room = (t_room*)ft_m(sizeof(t_room));
		room->x = ft_atoi(split[1]);
		room->y = ft_atoi(split[2]);
		room->name = ft_strdup(split[0]);
		if (split[1][ft_intlen(room->x)] || split[2][ft_intlen(room->x)])
			return (0);
		ft_parrpush((void***)&lemin->rooms, room);
		ft_parrfree((void**)split);
		lines++;
	}
	return (parse_links(lemin, lines));
}

char			parse(t_lemin *lemin)
{
	char		*line;
	char		**lines;

	lines = (char**)ft_parrnew();
	while ((line = ft_gnl(0)))
		ft_parrpush((void***)&lines, line);
	if (!*lines || (lemin->ants = ft_atoi(*lines)) <= 0 ||
	(*lines)[ft_intlen(lemin->ants)] || !parse_rooms(lemin, &lines[1]))
	{
		ft_printf(2, "ERROR\n");
		return (0);
	}
	ft_parrfree((void**)lines);
	return (1);
}
