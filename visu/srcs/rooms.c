/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:15:03 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 20:45:44 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	render_room(t_visu *visu, int i)
{
	SDL_Rect		rc;
	unsigned int	j;

	if (visu->rooms[i]->type == 1)
		print_text_big(visu, visu->rooms[i]->name, 0xff00,
		get_rect(520, 10, ROOM, ROOM));
	if (visu->rooms[i]->type == 2)
		print_text_big(visu, visu->rooms[i]->name, 0xff0000,
		get_rect(520, 35, ROOM, ROOM));
	rc = get_rect(visu->rooms[i]->x, visu->rooms[i]->y, ROOM, ROOM);
	SDL_FillRect(visu->surface, &rc, 0x606060);
	print_text(visu, visu->rooms[i]->name, 0xffffff - 0xff00ff *
	(visu->rooms[i]->type == 1) - 0xffff * (visu->rooms[i]->type == 2),
	get_rect(visu->rooms[i]->x, visu->rooms[i]->y + ROOM, ROOM, 20));
	j = 0;
	if (visu->rooms[i]->type == 1)
		while (j < ft_parrlen((void**)visu->ants))
		{
			visu->ants[j]->room = visu->rooms[i];
			visu->ants[j++]->dest = 0;
		}
	else if (visu->rooms[i]->type == 2)
		visu->end = visu->rooms[i];
}

static void	render_link(t_visu *visu, int i)
{
	int			dist[3];
	int			j;
	t_room		*rooms[2];
	SDL_Rect	rc;

	rooms[0] = get_room(visu, visu->links[i]->start);
	rooms[1] = get_room(visu, visu->links[i]->end);
	dist[0] = rooms[1]->x - rooms[0]->x;
	dist[1] = rooms[1]->y - rooms[0]->y;
	dist[2] = sqrt(pow(dist[0], 2) + pow(dist[1], 2));
	j = 0;
	while (j < dist[2])
	{
		rc = get_rect(ROOM / 2 + rooms[0]->x + dist[0] * ((float)j / dist[2]),
		ROOM / 2 + rooms[0]->y + dist[1] * ((float)j / dist[2]), 1, 1);
		SDL_FillRect(visu->surface, &rc, 0x606060);
		j++;
	}
}

void		render_rooms(t_visu *visu)
{
	unsigned int	i;

	i = 0;
	while (i < ft_parrlen((void**)visu->links))
		render_link(visu, i++);
	i = 0;
	while (i < ft_parrlen((void**)visu->rooms))
		render_room(visu, i++);
}
