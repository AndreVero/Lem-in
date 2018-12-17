/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:46:40 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/08 13:17:19 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		free_way(t_way *way)
{
	t_way		*t;

	while (way != NULL)
	{
		t = way;
		t = way->next;
		free(way->name);
		free(way);
		way = NULL;
		way = t;
	}
}

void		free_room(t_room *room)
{
	t_room	*tmp;
	t_list	*tmp1;

	while (room != NULL)
	{
		tmp = room->next;
		free(room->name);
		while (room->neib != NULL)
		{
			tmp1 = room->neib->next;
			free(room->neib->content);
			free(room->neib);
			room->neib = tmp1;
		}
		free(room);
		room = tmp;
	}
}
