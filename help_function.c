/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 16:54:36 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/08 16:46:08 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			free_2d(char **str, int i)
{
	int			j;

	j = 0;
	while (j < i)
	{
		free(str[j]);
		j++;
	}
	free(str);
}

t_ant			*find_last(t_ant *t)
{
	while (t->next != NULL)
		t = t->next;
	return (t);
}

int				find_step_of_ant(t_way *way)
{
	int			i;

	i = 0;
	while (way != NULL)
	{
		i++;
		way = way->next;
	}
	return (i);
}

int				way_check_zero(t_way *way)
{
	while (way != NULL)
	{
		if ((way)->ant != 0)
			return (0);
		way = (way)->next;
	}
	return (1);
}

int				check_comm(char *l)
{
	if (ft_strlen(l) >= 1)
	{
		if (ft_strlen(l) == 7)
			if (!ft_strcmp(l, "##start"))
				return (0);
		if (ft_strlen(l) == 5)
			if (!ft_strcmp(l, "##end"))
				return (0);
		if (l[0] == '#')
			return (1);
	}
	return (0);
}
