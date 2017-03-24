/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 17:58:06 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 20:05:50 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

static void		move_ant(t_lemin *lemin, t_room *origin, t_room *dst, int path)
{
	if (origin == lemin->start && lemin->path_ants[path])
	{
		dst->ant = lemin->next++;
		lemin->path_ants[path]--;
	}
	else if (origin != lemin->start)
	{
		dst->ant = origin->ant;
		origin->ant = 0;
	}
	else
		return ;
	ft_printf(1, "L%d-%s ", dst->ant, dst->name);
	if (dst == lemin->end)
		lemin->ants--;
}

void			run(t_lemin *lemin)
{
	int		amount;
	int		path;
	int		pos;

	amount = lemin->ants;
	lemin->start->ant = 1;
	while (lemin->ants)
	{
		path = 0;
		while (lemin->paths[path])
		{
			pos = (int)ft_parrlen((void**)lemin->paths[path]) - 1;
			while (pos)
			{
				if (lemin->paths[path][pos - 1]->ant)
					move_ant(lemin, lemin->paths[path][pos - 1],
					lemin->paths[path][pos], path);
				pos--;
			}
			path++;
		}
		ft_putchar('\n');
	}
}
