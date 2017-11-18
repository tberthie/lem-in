/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:21:25 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 21:46:36 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		event(SDL_Event ev, t_visu *visu)
{
	if (ev.type == SDL_WINDOWEVENT && ev.window.event == SDL_WINDOWEVENT_CLOSE)
		visu->quit = 1;
	if (ev.type == SDL_KEYDOWN)
	{
		if (ev.key.keysym.sym == SDLK_ESCAPE)
			visu->quit = 1;
		if (ev.key.keysym.sym == SDLK_SPACE)
			visu->pause = visu->pause ? 0 : 1;
		if (ev.key.keysym.sym == SDLK_q || ev.key.keysym.sym == SDLK_e)
		{
			visu->pause = 1;
			if (ev.key.keysym.sym == SDLK_q)
			{
				visu->step == visu->max_steps ? visu->status = 0 : 0;
				visu->step && !visu->status ? visu->step -= 1 : 0;
				visu->status ? visu->status = 0 : 0;
			}
			if (ev.key.keysym.sym == SDLK_e && visu->step < visu->max_steps)
			{
				visu->step++;
				visu->status = 0;
			}
		}
	}
}

static void		rooms_coords(t_visu *visu)
{
	unsigned int	i;

	i = 0;
	while (i < ft_parrlen((void**)visu->rooms))
	{
		visu->rooms[i]->x = 20 + (float)(visu->rooms[i]->x - visu->limits[0]) /
		(visu->limits[1] - visu->limits[0] + 0.01) * (WINX - 40 - ROOM);
		visu->rooms[i]->y = 120 + (float)(visu->rooms[i]->y - visu->limits[2]) /
		(visu->limits[3] - visu->limits[2] + 0.01) * (WINY - 140 - ROOM);
		i++;
	}
}

void			run(t_visu *visu)
{
	SDL_Event	ev;

	rooms_coords(visu);
	render(visu);
	while (!visu->quit)
	{
		while (SDL_PollEvent(&ev))
			event(ev, visu);
		render(visu);
	}
}
