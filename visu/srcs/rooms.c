/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:15:03 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 14:40:51 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void	render_room(t_visu *visu, int i)
{
	float		coords[2];

	coords[0] = (float)(visu->rooms[i]->x - visu->limits[0]) /
	(visu->limits[1] - visu->limits[0] + 0.01);
	coords[1] = (float)(visu->rooms[i]->y - visu->limits[2]) /
	(visu->limits[3] - visu->limits[2] + 0.01);
	if (visu->rooms[i]->type == 1)
		print_text_big(visu, visu->rooms[i]->name, 0xff00,
		get_rect(520, 10, ROOM, ROOM));
	if (visu->rooms[i]->type == 2)
		print_text_big(visu, visu->rooms[i]->name, 0xff0000,
		get_rect(520, 35, ROOM, ROOM));
	rc = get_rect(0, 0, ROOM, ROOM):
}

void		render_rooms(t_visu *visu)
{
	unsigned int	i;

	i = 0;
	while (i < ft_parrlen((void**)visu->rooms))
		render_room(visu, i++);
}
