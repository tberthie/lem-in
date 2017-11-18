/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:30:38 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 21:46:28 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void		render(t_visu *visu)
{
	SDL_Texture		*tx;

	if (visu->step == visu->max_steps)
		visu->status = 1;
	if (visu->step <= visu->max_steps)
	{
		stats(visu);
		render_rooms(visu);
		refresh(visu);
		render_ants(visu);
		tx = SDL_CreateTextureFromSurface(visu->ren, visu->surface);
		SDL_RenderCopy(visu->ren, tx, 0, 0);
		SDL_DestroyTexture(tx);
		SDL_RenderPresent(visu->ren);
	}
	if (!visu->pause && visu->status < 1)
		visu->status += 0.005;
	else if (!visu->pause && visu->step != visu->max_steps)
	{
		visu->step++;
		visu->status = 0;
	}
}
