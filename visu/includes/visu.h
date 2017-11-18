/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:18:15 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 20:43:52 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H

# include "libft.h"
# include "SDL.h"
# include "SDL_ttf.h"

# include <limits.h>
# include <math.h>

# define WINX	1500
# define WINY	1000
# define ROOM	60

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	char			type;

}				t_room;

typedef struct	s_ant
{
	t_room			*room;
	t_room			*dest;

}				t_ant;

typedef struct	s_link
{
	char			*start;
	char			*end;

}				t_link;

typedef struct	s_visu
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	TTF_Font		*small;
	TTF_Font		*big;
	SDL_Surface		*surface;

	char			quit;
	char			pause;

	t_room			**rooms;
	t_room			*end;
	t_link			**links;
	t_ant			**ants;
	int				limits[4];

	unsigned int	step;
	unsigned int	max_steps;
	float			status;
	char			**moves;

}				t_visu;

void			run(t_visu *visu);
void			render(t_visu *visu);
t_visu			*parse(t_visu *visu, char **data);

void			render_rooms(t_visu *visu);
void			render_ants(t_visu *visu);
void			refresh(t_visu *visu);
void			stats(t_visu *visu);

SDL_Rect		get_rect(int x, int y, int w, int h);
SDL_Color		get_color(unsigned int color);
void			print_text(t_visu *visu, char *txt, unsigned int color,
				SDL_Rect rc);
void			print_text_big(t_visu *visu, char *txt, unsigned int color,
				SDL_Rect rc);
t_room			*get_room(t_visu *visu, char *name);

#endif
