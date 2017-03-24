/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:49:01 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 21:01:22 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

#include <stdlib.h>

static char		**find_path(t_lemin *lemin, t_room *room, int depth,
				char ***path)
{
	int		i;
	char	**tmp;

	i = 0;
	while (depth && room->links[i])
	{
		if (room->links[i] == lemin->end)
		{
			ft_parrpush((void***)path, room->links[i]->name);
			return (*path);
		}
		if (room->links[i]->status == 1)
		{
			ft_parrpush((void***)path, room->links[i]->name);
			if ((tmp = find_path(lemin, room->links[i], depth - 1, path)))
				return (tmp);
			(*path)[ft_parrlen((void**)(*path)) - 1] = 0;
		}
		i++;
	}
	return (0);
}

static void		lock_path(t_lemin *lemin, char **path)
{
	int		i;
	int		pos;

	i = 0;
	while (lemin->rooms[i])
	{
		if (lemin->rooms[i] != lemin->start && lemin->rooms[i] != lemin->end &&
		(pos = ft_strarrstr(path, lemin->rooms[i]->name)) != -1)
		{
			lemin->rooms[i]->status = 0;
			lemin->rooms[i]->path = (int)ft_parrlen((void**)lemin->paths) - 1;
			lemin->rooms[i]->pos = pos;
			lemin->rooms[i]->ant = 0;
		}
		i++;
	}
}

static void		check_ants(t_lemin *lemin)
{
	int		sum;
	int		i;

	sum = 0;
	i = 0;
	while (lemin->paths[i])
		sum += lemin->path_ants[i++];
	if (sum < lemin->ants)
		*lemin->path_ants += lemin->ants - sum;
	if (sum > lemin->ants)
		lemin->path_ants[i - 1] -= sum - lemin->ants;
	ft_putstr(lemin->output);
	free(lemin->output);
	run(lemin);	
}

static void		get_ratio(t_lemin *lemin)
{
	unsigned int	min;
	double			sum;
	unsigned int	i;

	i = 0;
	sum = 0;
	min = ft_parrlen((void**)lemin->rooms);
	while (lemin->paths[i])
		if (ft_parrlen((void**)lemin->paths[i++]) < min)
			min = ft_parrlen((void**)lemin->paths[i - 1]);
	lemin->ratio = (double*)ft_m(sizeof(double) * i);
	i = 0;
	while (lemin->paths[i])
	{
		lemin->ratio[i] = (double)min / ft_parrlen((void**)lemin->paths[i]);
		sum += lemin->ratio[i++];
	}
	lemin->path_ants = (int*)ft_m(sizeof(int) * i);
	i = 0;
	while (lemin->paths[i])
	{
		lemin->path_ants[i] = (int)(lemin->ants * (lemin->ratio[i] / sum));
		i++;
	}
	check_ants(lemin);
}

static t_room	**convert_path(t_lemin *lemin, char **path)
{
	t_room	**conv;
	int		i;

	conv = (t_room**)ft_parrnew();
	while (*path)
	{
		i = 0;
		while (ft_strcmp(lemin->rooms[i]->name, *path))
			i++;
		ft_parrpush((void***)&conv, lemin->rooms[i]);
		path++;
	}
	return (conv);
}

void			solve(t_lemin *lemin)
{
	char		**path;
	char		**tmp;
	int			depth;

	depth = 1;
	lemin->paths = (t_room***)ft_parrnew();
	while (lemin->npaths && lemin->rooms[depth])
	{
		path = (char**)ft_parrnew();
		ft_parrpush((void***)&path, lemin->start->name);
		depth += (tmp = find_path(lemin, lemin->start, depth, &path)) ? 0 : 1;
		if (tmp)
		{
			ft_parrpush((void***)&lemin->paths, convert_path(lemin, path));
			lock_path(lemin, path);
			lemin->npaths--;
		}
		free(path);
	}
	if (!(lemin->npaths = ft_parrlen((void**)lemin->paths)))
		ft_printf(2, "ERROR\n");
	else
		get_ratio(lemin);
}
