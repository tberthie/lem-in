/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:47:36 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 19:09:56 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

#include <stdlib.h>

static char		parse_rooms(t_lemin *lemin)
{
	return (1);
}

char			parse(t_lemin *lemin)
{
	char		*line;

	if (!(line = ft_gnl(0)) || (lemin->ants = ft_atoi(line)) <= 0 ||
	line[ft_intlen(lemin->ants)] || !parse_rooms(lemin))
	{
		ft_printf(2, "ERROR\n");
		return (0);
	}
	if (line)
		free(line);
	return (1);
}
