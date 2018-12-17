/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:18:20 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/11 15:14:37 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int				ft_check_comment(char *l)
{
	if (ft_strlen(l) >= 2)
		if (l[0] == '#' && l[1] == '#')
			return (1);
	if (ft_strlen(l) >= 1)
		if (l[0] == '#')
			return (1);
	return (0);
}

char					*ft_check_str(char **str, char *l)
{
	if (ft_check_comment(l))
	{
		*str = my_strjoin(*str, l);
		return (NULL);
	}
	else if (ft_strstr(l, " "))
	{
		*str = my_strjoin(*str, l);
		if (check_rooms(l))
			return (ft_strdup("Error in room\n"));
		return (NULL);
	}
	else if (ft_strstr(l, "-"))
	{
		*str = my_strjoin(*str, l);
		if (check_links(l))
			return (ft_strdup("Error in link\n"));
		return (NULL);
	}
	return (ft_strdup("Bad input text\n"));
}

int						put_to_solver(int a, t_room *t, t_room *end, char *test)
{
	if (!check_start(&t))
		return (1);
	if (check_end(end))
		return (1);
	if (a <= 0 || solver(a, t, end, test))
	{
		if (t)
			free_room(t);
		ft_putstr("ERROR\n");
		return (1);
	}
	return (0);
}

int						check_all(char **str, char *l, t_all *rooms, int ants)
{
	char				*s;

	s = NULL;
	if (!(*str) && ft_strlen(l) >= 1 && check_comm(l))
		return (create_comm(str, l));
	if (!(*str))
	{
		ft_putstr("ERROR\nBad count of ants\n");
		return (1);
	}
	else
	{
		ft_strcat(*str, "\n");
		if (!(s = ft_check_str(str, l)))
			return (0);
		else
		{
			if (put_to_solver(ants, rooms->tmp, rooms->end, *str))
				ft_putstr(s);
			if (s)
				free(s);
			return (1);
		}
	}
	return (0);
}

int						main(void)
{
	char				*l;
	t_all				*rooms;
	int					ants;
	char				*test;

	rooms = (t_all *)malloc(sizeof(t_all));
	rooms->tmp = NULL;
	test = NULL;
	rooms->end = NULL;
	ants = -1;
	while (get_next_line(0, &l) > 0)
	{
		if (read_from_output(&test, &rooms, &ants, l))
			return (not_valid(rooms));
		if (l)
			free(l);
	}
	if (!rooms->tmp)
		return (not_valid(rooms));
	if (put_to_solver(ants, rooms->tmp, rooms->end, test))
		return (1);
	free_room(rooms->tmp);
	return (0);
}
