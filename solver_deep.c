/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_deep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 19:05:30 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/11 14:15:02 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_way		*create_the_way(t_room *end)
{
	t_way			*way;
	t_way			*tmp;
	t_room			*test;

	test = end->prev;
	way = (t_way *)malloc(sizeof(t_way));
	way->name = ft_strdup(end->name);
	way->ant = 0;
	way->next = NULL;
	way->prev = NULL;
	while (test->prev != NULL)
	{
		tmp = (t_way *)malloc(sizeof(t_way));
		tmp->name = ft_strdup(test->name);
		tmp->ant = 0;
		tmp->prev = NULL;
		tmp->next = way;
		way->prev = tmp;
		way = tmp;
		test = test->prev;
	}
	return (way);
}

static t_ant		*count_ants(int ants)
{
	int				i;
	t_ant			*tmp;
	t_ant			*res;
	t_ant			*ant;

	i = 1;
	ant = NULL;
	if (ants > 0)
	{
		res = (t_ant *)malloc(sizeof(t_ant));
		ant = res;
		res->number = 1;
		res->next = NULL;
	}
	while (++i <= ants)
	{
		tmp = (t_ant *)malloc(sizeof(t_ant));
		tmp->number = i;
		tmp->next = NULL;
		res = find_last(res);
		res->next = tmp;
	}
	return (ant);
}

static void			walk_in_way(t_way *way)
{
	while (way->next != NULL)
		way = way->next;
	while (way != NULL)
	{
		if (way->prev != NULL)
			way->ant = way->prev->ant;
		way = way->prev;
	}
}

void				ant_manipulator(t_ant **ant)
{
	t_ant			*ant1;

	ant1 = *ant;
	*ant = (*ant)->next;
	free(ant1);
}

void				find_the_short_way(int ants, t_room *end)
{
	t_way			*way;
	t_ant			*ant;
	int				i;
	int				step;

	i = -1;
	ant = count_ants(ants);
	way = create_the_way(end);
	step = find_step_of_ant(way);
	while (++i < ants * step)
	{
		walk_in_way(way);
		if (ant != NULL)
			way->ant = ant->number;
		if (ant == NULL)
			way->ant = 0;
		if (way_check_zero(way))
			break ;
		print_way(way);
		if (ant)
			ant_manipulator(&ant);
	}
	free_way(way);
}
