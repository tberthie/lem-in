/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 14:28:34 by tberthie          #+#    #+#             */
/*   Updated: 2017/11/18 20:54:46 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

static void		set_ant(t_visu *visu, char *move)
{
	t_ant	*ant;

	ant = visu->ants[ft_atoi(&move[1]) - 1];
	move = ft_strchr(move, '-') + 1;
	ant->room = ant->dest ? ant->dest : ant->room;
	ant->dest = get_room(visu, move);
}

static void		check_end(t_visu *visu)
{
	unsigned int	i;

	i = 0;
	while (i < ft_parrlen((void**)visu->ants))
	{
		if (visu->ants[i]->dest == visu->end)
			visu->ants[i]->room = visu->end;
		i++;
	}
}

void			refresh(t_visu *visu)
{
	unsigned int	i;
	unsigned int	j;
	char			**split;

	i = 0;
	while (i < ft_parrlen((void**)visu->ants))
		visu->ants[i++]->dest = 0;
	i = 0;
	while (i < ft_parrlen((void**)visu->moves) && i <= visu->step)
	{
		check_end(visu);
		split = ft_strsplit(visu->moves[i], ' ');
		j = 0;
		while (j < ft_parrlen((void**)split))
			set_ant(visu, split[j++]);
		ft_parrfree((void**)split);
		i++;
	}
}
