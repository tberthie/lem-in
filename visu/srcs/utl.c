/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 01:42:20 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 20:33:41 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

SDL_Rect		get_rect(int x, int y, int w, int h)
{
	SDL_Rect	rc;

	rc.x = x;
	rc.y = y;
	rc.w = w;
	rc.h = h;
	return (rc);
}

SDL_Color		get_color(unsigned int color)
{
	SDL_Color	sc;

	sc.r = (color >> 16) & 0xff;
	sc.g = (color >> 8) & 0xff;
	sc.b = color & 0xff;
	return (sc);
}

void			print_text(t_visu *visu, char *txt, unsigned int color,
				SDL_Rect rc)
{
	SDL_Surface		*sf;

	sf = TTF_RenderText_Shaded(visu->small, txt, get_color(color),
	get_color(0));
	SDL_BlitSurface(sf, 0, visu->surface, &rc);
	SDL_FreeSurface(sf);
}

void			print_text_big(t_visu *visu, char *txt, unsigned int color,
				SDL_Rect rc)
{
	SDL_Surface		*sf;

	sf = TTF_RenderText_Shaded(visu->big, txt, get_color(color),
	get_color(0));
	SDL_BlitSurface(sf, 0, visu->surface, &rc);
	SDL_FreeSurface(sf);
}

t_room			*get_room(t_visu *visu, char *name)
{
	unsigned int	i;

	i = 0;
	while (i < ft_parrlen((void**)visu->rooms))
	{
		if (!ft_strcmp(visu->rooms[i]->name, name))
			return (visu->rooms[i]);
		i++;
	}
	return (0);
}
