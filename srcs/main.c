/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberthie <tberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:40:29 by tberthie          #+#    #+#             */
/*   Updated: 2017/03/09 18:50:41 by tberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			main(void)
{
	t_lemin		lemin;

	lemin.start = 0;
	lemin.end = 0;
	if (parse(&lemin))
		solve(&lemin);
	return (0);
}
