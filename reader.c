/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:10:20 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/11 15:08:01 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ants_checker(char *l)
{
	while (*l != '\0')
	{
		if (!ft_isdigit(*l))
			return (0);
		l++;
	}
	return (1);
}

int			check_start(t_room **tmp)
{
	t_room	*t;

	t = NULL;
	t = *tmp;
	if (!tmp || !(*tmp))
	{
		ft_putstr("ERROR\nStart\n");
		return (0);
	}
	while (t)
	{
		if (t->start == 1)
			return (1);
		t = t->next;
	}
	ft_putstr("ERROR\nStart\n");
	return (0);
}

int			check_end(t_room *end)
{
	if (!end)
	{
		ft_putstr("ERROR\nEnd\n");
		return (1);
	}
	if (end->neib == NULL)
	{
		ft_putstr("ERROR\nEnd\n");
		return (1);
	}
	return (0);
}

int			read_from_output(char **test, t_all **rooms, int *ants, char *l)
{
	if (ants_checker(l) && *ants == -1)
	{
		if (!(*test))
			*test = ft_strdup(l);
		else
			create_ant_after_comm(test, l);
		*ants = ft_atoi(l);
	}
	else if (check_all(test, l, *rooms, *ants))
		return (1);
	if (!ft_strcmp(l, "##start"))
	{
		if (!((*rooms)->tmp = create_start((*rooms)->tmp, 0, test)))
			return (1);
	}
	else if (!ft_strcmp(l, "##end"))
		(*rooms)->end = create_end(0, test);
	else if (ft_strstr(l, " ") && ft_strlen(l) > 4 && l[0] != '#')
		create_new_room(l, &(*rooms)->tmp);
	else if (ft_strlen(l) > 2 && ft_strstr(l, "-"))
	{
		add_end((*rooms)->tmp, (*rooms)->end);
		find_neighbors(l, (*rooms)->tmp);
	}
	return (0);
}
