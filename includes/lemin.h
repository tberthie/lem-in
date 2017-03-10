/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:40:47 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/10 14:23:50 by tberthie         ###   ########.fr       */
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
}					t_room;

typedef struct		s_lemin
{
	t_room			**rooms;

	t_room			*start;
	t_room			*end;

	int				ants;

	char			pad[4];
}					t_lemin;

char				parse(t_lemin *lemin);
void				solve(t_lemin *lemin);

#endif
