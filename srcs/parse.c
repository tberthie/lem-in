/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:47:36 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 23:18:54 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

#include <stdlib.h>

static char		check(t_lemin *lemin, char **lines, long offset)
{
	int		i;

	i = 0;
	if (!lemin->start || !lemin->end)
		return (0);
	lemin->npaths = ft_parrlen((void**)lemin->start->links);
	if (ft_parrlen((void**)lemin->end->links) < lemin->npaths)
		lemin->npaths = ft_parrlen((void**)lemin->end->links);
	if (lemin->npaths)
	{
		while (offset--)
		{
			ft_strpush(&lines[i], '\n');
			ft_strspush(&lemin->output, lines[i++]);
		}
		ft_strpush(&lemin->output, '\n');
	}
	ft_parrfree((void**)lines);
	return (lemin->npaths) ? 1 : 0;
}

static char		**parse_links(t_lemin *lemin, char **lines)
{
	char	**split;
	int		i;
	int		j;

	lines = skip_coms(lines);
	while (*lines)
	{
		if (ft_strcount(*lines, '-') != 1 || ft_parrlen((void**)(split =
		ft_strsplit(*lines, '-'))) != 2 || !ft_strcmp(split[0], split[1]))
			break ;
		i = 0;
		while (lemin->rooms[i] && ft_strcmp(lemin->rooms[i]->name, split[0]))
			i++;
		j = 0;
		while (lemin->rooms[j] && ft_strcmp(lemin->rooms[j]->name, split[1]))
			j++;
		if (!lemin->rooms[i] || !lemin->rooms[j])
			break ;
		ft_parrpush((void***)&lemin->rooms[i]->links, lemin->rooms[j]);
		ft_parrpush((void***)&lemin->rooms[j]->links, lemin->rooms[i]);
		ft_parrfree((void**)split);
		lines = skip_coms(lines + 1);
	}
	return (lines);
}

static char		add_room(t_lemin *lemin, t_room *room, char spe)
{
	if ((spe == 1 && lemin->start) || (spe == 2 && lemin->end))
		return (0);
	ft_parrpush((void***)&lemin->rooms, room);
	lemin->start = spe == 1 ? room : lemin->start;
	lemin->end = spe == 2 ? room : lemin->end;
	room->status = spe ? 2 : 1;
	return (1);
}

static char		**parse_rooms(t_lemin *lemin, char **lines)
{
	t_room		*room;
	char		**split;
	char		spe;

	spe = 0;
	lines = skip_coms(lines);
	while (*lines && !((*lines)[ft_intlen(ft_atoi(*lines))] == '-'))
	{
		if (!ft_strcmp(*lines, "##start") || !ft_strcmp(*lines, "##end"))
			spe = 1 + !ft_strcmp(*lines++, "##end");
		if (!*lines || ft_strcount(*lines, ' ') != 2 || **lines == 'L' ||
		ft_parrlen((void**)(split = ft_strsplit(*lines, ' '))) != 3)
			break ;
		room = (t_room*)ft_m(sizeof(t_room));
		room->x = ft_atoi(split[1]);
		room->y = ft_atoi(split[2]);
		room->name = ft_strdup(split[0]);
		room->links = (t_room**)ft_parrnew();
		if (split[1][ft_intlen(room->x)] || split[2][ft_intlen(room->y)] ||
		!add_room(lemin, room, spe) || (spe = 0))
			break ;
		ft_parrfree((void**)split);
		lines = skip_coms(lines + 1);
	}
	return (parse_links(lemin, spe ? lines - 1 : lines));
}

char			parse(t_lemin *lemin)
{
	char		*line;
	char		**lines;
	char		**offset;
	int			i;

	lines = (char**)ft_parrnew();
	while ((line = ft_gnl(0)))
		ft_parrpush((void***)&lines, line);
	i = 0;
	while (lines[i] && *lines[i] == '#' && *(lines[i] + 1) != '#')
		i++;
	if (!lines[i] || (lemin->ants = ft_atoi(lines[i])) <= 0 ||
	lines[i][ft_intlen(lemin->ants)])
	{
		ft_printf(2, "ERROR\n");
		return (0);
	}
	offset = parse_rooms(lemin, &lines[i + 1]);
	if (check(lemin, lines, offset - lines))
		return (1);
	ft_printf(2, "ERROR\n");
	return (0);
}
