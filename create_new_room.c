/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_room.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:21:18 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/07 15:09:53 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	put_in_tmp(t_room **t)
{
	(*t)->neib = NULL;
	(*t)->next = NULL;
	(*t)->start = 0;
}

void		create_new_room(char *l, t_room **t)
{
	t_room	*tmp;
	char	**str;
	t_room	*test;

	str = NULL;
	if (*t)
	{
		test = (*t);
		tmp = (t_room*)malloc(sizeof(t_room));
		while (test->next != NULL)
			test = test->next;
		test->next = tmp;
	}
	else
	{
		(*t) = (t_room*)malloc(sizeof(t_room));
		tmp = (*t);
	}
	str = ft_strsplit(l, ' ');
	tmp->x = ft_atoi(str[2]);
	tmp->y = ft_atoi(str[1]);
	tmp->name = ft_strdup(str[0]);
	put_in_tmp(&tmp);
	free_2d(str, 3);
}
