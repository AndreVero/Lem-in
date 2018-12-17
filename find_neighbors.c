/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_neighbors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:56:20 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/09 14:58:55 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void				find_neighbors_1(char *str1, char *str2, t_room *tmp)
{
	t_room				*t;

	t = tmp;
	while (t != NULL)
	{
		if (!ft_strcmp(t->name, str1))
		{
			if (t->neib == NULL)
				t->neib = ft_lstnew(str2, sizeof(str2));
			else
				ft_lstadd(&t->neib, ft_lstnew(str2, sizeof(str2)));
			return ;
		}
		t = t->next;
	}
}

static int				not_in_room(char *str, t_room *t)
{
	while (t != NULL)
	{
		if (!ft_strcmp(t->name, str))
			return (0);
		t = t->next;
	}
	return (1);
}

void					find_neighbors(char *l, t_room *t)
{
	char				**str;

	str = ft_strsplit(l, '-');
	if (not_in_room(str[0], t) || not_in_room(str[1], t))
	{
		free(str[0]);
		free(str[1]);
		free(str);
		return ;
	}
	find_neighbors_1(str[0], str[1], t);
	find_neighbors_1(str[1], str[0], t);
	free(str[0]);
	free(str[1]);
	free(str);
}
