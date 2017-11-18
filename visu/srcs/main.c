/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:28:48 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/16 22:54:42 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		setup(char **data)
{
	t_visu	*visu;

	visu = (t_visu*)ft_memalloc(sizeof(t_visu));
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) &&
	(visu->win = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, WINX, WINY, SDL_WINDOW_SHOWN)) && (visu->ren =
	SDL_CreateRenderer(visu->win, -1, SDL_RENDERER_ACCELERATED)) &&
	!TTF_Init() && (visu->small = TTF_OpenFont("font.ttf", ROOM / 5)) &&
	(visu->big = TTF_OpenFont("font.ttf", ROOM / 3)))
	{
		visu = parse(visu, data);
		run(visu);
	}
	else
		ft_print(2, "lem-in: %s\n", SDL_GetError());
	free(visu);
	SDL_Quit();
}

int				main(void)
{
	char	**data;
	char	*gnl;

	data = (char**)ft_parrnew();
	while ((gnl = ft_gnl(0)))
		ft_parrpush((void***)&data, gnl);
	if (ft_parrlen((void**)data) && ft_strcmp(data[0], "ERROR"))
		setup(data);
	ft_free(gnl);
	ft_parrfree((void**)data);
	return (0);
}
