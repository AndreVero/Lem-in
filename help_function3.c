/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:00:02 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/11 15:06:57 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				no_way(t_room *t, t_room *end)
{
	while (end->prev != NULL)
		end = end->prev;
	if (!ft_strcmp(end->name, t->name))
		return (0);
	return (1);
}

int				all_checked(t_room *t)
{
	while (t)
	{
		if (t->checked == 0)
			return (1);
		t = t->next;
	}
	return (0);
}

int				find_end(t_room *end)
{
	if (end->checked)
		return (1);
	return (0);
}
