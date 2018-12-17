/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_end.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:48:49 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/09 14:12:22 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_end(t_room *t, t_room *end)
{
	t->end = end;
	if (!end)
		return ;
	while (t->next != NULL)
		t = t->next;
	if (!ft_strcmp(t->name, end->name) &&
			t->x == end->x && t->y == end->y)
		return ;
	end->next = NULL;
	t->next = end;
}
