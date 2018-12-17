/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 15:15:29 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/09 14:38:20 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*create_end(int fd, char **test)
{
	char		**str;
	t_room		*tmp;
	char		*l;

	get_next_line(fd, &l);
	if (check_rooms(l))
	{
		free(l);
		return (NULL);
	}
	ft_strcat(*test, "\n");
	*test = my_strjoin(*test, l);
	tmp = (t_room*)malloc(sizeof(t_room));
	str = ft_strsplit(l, ' ');
	tmp->x = ft_atoi(str[2]);
	tmp->y = ft_atoi(str[1]);
	tmp->name = ft_strdup(str[0]);
	tmp->neib = NULL;
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str);
	free(l);
	return (tmp);
}
