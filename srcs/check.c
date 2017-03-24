/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 12:17:12 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 13:47:10 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

char		check(t_lemin *lemin)
{
	if (!lemin->start || !lemin->end)
		return (0);
	lemin->paths = ft_parrlen((void**)lemin->start->links);
	if (ft_parrlen((void**)lemin->end->links) < lemin->paths)
		lemin->paths = ft_parrlen((void**)lemin->end->links);
	ft_printf(1, "%d\n", lemin->paths);
	return (lemin->paths) ? 1 : 0;
}
