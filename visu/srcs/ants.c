/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:15:24 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 20:18:34 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		moving(t_visu *visu, t_ant *ant)
{
	int			dist[2];
	SDL_Rect	rc;

	dist[0] = ant->dest->x - ant->room->x;
	dist[1] = ant->dest->y - ant->room->y;
	rc = get_rect(ROOM / 2 + ant->room->x + dist[0] * visu->status - ROOM / 12,
	ROOM / 2 + ant->room->y + dist[1] * visu->status - ROOM / 12,
	ROOM / 6, ROOM / 6);
	SDL_FillRect(visu->surface, &rc, 0xff0000);
}

void			render_ants(t_visu *visu)
{
	unsigned int	i;
	t_ant			*ant;
	SDL_Rect		rc;

	i = 0;
	while (i < ft_parrlen((void**)visu->ants))
	{
		ant = visu->ants[i];
		if (ant->dest)
			moving(visu, ant);
		else
		{
			rc = get_rect(ROOM / 2 + ant->room->x - ROOM / 12, ROOM / 2 +
			ant->room->y - ROOM / 12, ROOM / 6, ROOM / 6);
			SDL_FillRect(visu->surface, &rc, 0xff0000);
		}
		i++;
	}
}
