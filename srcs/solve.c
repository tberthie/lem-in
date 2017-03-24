/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:49:01 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 13:32:24 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

void			solve(t_lemin *lemin)
{
	t_room	*room;

	while (*lemin->rooms)
	{
		room = *lemin->rooms++;
		ft_printf(1, "Room %s %d %d\nLinks ", room->name, room->x, room->y);
		while (*room->links)
			ft_printf(1, "%s ", (*room->links++)->name);
		ft_printf(1, "\n\n");
	}
	ft_printf(1, "%d paths\n", lemin->paths);
}
