/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 23:06:20 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 23:17:46 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

t_room		**convert_path(t_lemin *lemin, char **path)
{
	t_room	**conv;
	int		i;

	conv = (t_room**)ft_parrnew();
	while (*path)
	{
		i = 0;
		while (ft_strcmp(lemin->rooms[i]->name, *path))
			i++;
		ft_parrpush((void***)&conv, lemin->rooms[i]);
		path++;
	}
	return (conv);
}

char		**skip_coms(char **lines)
{
	while (*lines && **lines == '#' && *(*lines + 1) != '#')
		lines++;
	return (lines);
}
