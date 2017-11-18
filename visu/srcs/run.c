/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:21:25 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 14:27:10 by tberthie         ###   ########.fr       */
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
			visu->status = 0;
			ev.key.keysym.sym == SDLK_q && visu->step ? visu->step-- : 0;
			ev.key.keysym.sym == SDLK_e && visu->step <= visu->max_steps ?
			visu->step++ : 0;
		}
	}
}

void			run(t_visu *visu)
{
	SDL_Event	ev;

	render(visu);
	while (!visu->quit)
	{
		while (SDL_PollEvent(&ev))
			event(ev, visu);
		render(visu);
	}
}
