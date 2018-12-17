/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:38:36 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/11 15:15:01 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room			*find_room(t_room *t, char *str)
{
	while (t != NULL)
	{
		if (!ft_strcmp(t->name, str))
			return (t);
		t = t->next;
	}
	return (NULL);
}

static void				free_rooms(t_room *t)
{
	while (t != NULL)
	{
		t->prev = NULL;
		t->number = 0;
		t->checked = 0;
		t = t->next;
	}
}

static void				find_the_way(t_room *t, int n, t_room *start)
{
	t_list				*l;

	l = t->neib;
	t->checked = 1;
	while (l != NULL)
	{
		if (find_room(start, (char *)l->content) != NULL &&
					find_room(start, (char *)l->content)->number == 0)
		{
			find_room(start, (char *)l->content)->prev = t;
			find_room(start, (char *)l->content)->number = n + 1;
		}
		l = l->next;
	}
}

static	t_room			*find_the_smallest(t_room *t)
{
	t_room				*tmp;

	tmp = NULL;
	while (t)
	{
		if ((tmp == NULL || t->number < tmp->number)
				&& !t->checked && t->number != 0)
			tmp = t;
		t = t->next;
	}
	return (tmp);
}

int						solver(int ants, t_room *t, t_room *end, char *test)
{
	free_rooms(t);
	t->prev = NULL;
	t->number = 1;
	if (!t || !end)
		return (1);
	while (all_checked(t) && !find_end(end))
	{
		if (!find_the_smallest(t))
			break ;
		else
			find_the_way(find_the_smallest(t), find_the_smallest(t)->number, t);
	}
	if (no_way(t, end))
		return (1);
	ft_putstr(test);
	if (ft_strlen(test) >= 1 && test[ft_strlen(test) - 1] == '\n')
		ft_putstr("\n");
	else
		ft_putstr("\n\n");
	find_the_short_way(ants, end);
	return (0);
}
