/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:56:14 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/09 14:33:00 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*return_null(char *l)
{
	if (l)
		free(l);
	return (NULL);
}

t_room			*create_start(t_room *t, int fd, char **test)
{
	char		**str;
	t_room		*tmp;
	char		*l;

	l = NULL;
	get_next_line(fd, &l);
	if (!l || ft_strlen(l) < 4 || check_rooms(l))
		return (return_null(l));
	ft_strcat(*test, "\n");
	*test = my_strjoin(*test, l);
	tmp = (t_room*)malloc(sizeof(t_room));
	str = ft_strsplit(l, ' ');
	tmp->x = ft_atoi(str[2]);
	tmp->y = ft_atoi(str[1]);
	tmp->name = ft_strdup(str[0]);
	tmp->next = t;
	tmp->start = 1;
	tmp->neib = NULL;
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
	free(l);
	return (tmp);
}
