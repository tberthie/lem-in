/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:42:29 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 21:30:42 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		stats_2(t_visu *visu)
{
	float			progress;
	SDL_Rect		rc;

	progress = ((float)visu->step + visu->status) / visu->max_steps;
	rc = get_rect(0, 95, WINX * progress, 4);
	SDL_FillRect(visu->surface, &rc, 0xffffff);
	if (visu->pause)
		print_text_big(visu, "PAUSED", 0xff0000, get_rect(400, 60, ROOM, ROOM));
}

void			stats(t_visu *visu)
{
	char		*tmp;
	SDL_Rect	rc;

	rc = get_rect(0, 0, WINX, WINY);
	SDL_FillRect(visu->surface, &rc, 0);
	rc = get_rect(0, 94, WINX, 1);
	SDL_FillRect(visu->surface, &rc, 0xffffff);
	rc = get_rect(0, 99, WINX, 1);
	SDL_FillRect(visu->surface, &rc, 0xffffff);
	print_text_big(visu, "ANTS", 0xffff00, get_rect(20, 10, ROOM, ROOM));
	print_text_big(visu, (tmp = ft_itoa(ft_parrlen((void**)visu->ants))),
	0xffffff, get_rect(200, 10, ROOM, ROOM));
	free(tmp);
	print_text_big(visu, "STEP", 0xffff00, get_rect(20, 35, ROOM, ROOM));
	print_text_big(visu, (tmp = ft_itoa((float)(visu->step))),
	0xffffff, get_rect(200, 35, ROOM, ROOM));
	free(tmp);
	print_text_big(visu, "END STEP", 0xffff00, get_rect(20, 60, ROOM, ROOM));
	print_text_big(visu, (tmp = ft_itoa((float)(visu->max_steps))),
	0xffffff, get_rect(200, 60, ROOM, ROOM));
	free(tmp);
	print_text_big(visu, "START", 0xffff00, get_rect(400, 10, ROOM, ROOM));
	print_text_big(visu, "END", 0xffff00, get_rect(400, 35, ROOM, ROOM));
	stats_2(visu);
}
