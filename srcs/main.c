/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:40:29 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/24 19:31:07 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

#include "libft.h"

int				main(void)
{
	t_lemin		lemin;

	lemin.start = 0;
	lemin.end = 0;
	lemin.next = 1;
	lemin.rooms = (t_room**)ft_parrnew();
	lemin.output = ft_strnew();
	if (parse(&lemin))
		solve(&lemin);
	return (0);
}
