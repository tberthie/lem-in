/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:40:47 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 23:17:37 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

typedef struct		s_room
{
	char			*name;
	struct s_room	**links;

	int				x;
	int				y;

	char			status;
	char			pad[3];

	int				path;
	int				pos;
	int				ant;
}					t_room;

typedef struct		s_lemin
{
	t_room			**rooms;

	t_room			*start;
	t_room			*end;

	int				ants;
	int				next;

	t_room			***paths;
	unsigned int	npaths;

	char			pad[4];

	double			*ratio;
	int				*path_ants;

	char			*output;
}					t_lemin;

char				parse(t_lemin *lemin);
void				solve(t_lemin *lemin);
void				run(t_lemin *lemin);

t_room				**convert_path(t_lemin *lemin, char **path);
char				**skip_coms(char **lines);

#endif
