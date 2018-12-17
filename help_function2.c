/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_function2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:41:25 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/08 16:45:38 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			create_comm(char **str, char *l)
{
	*str = my_strjoin(ft_strdup(""), l);
	return (0);
}

int			not_valid(t_all *r)
{
	if (!r->tmp)
		ft_putstr("ERROR\n");
	return (1);
}

void		create_ant_after_comm(char **test, char *l)
{
	ft_strcat(*test, "\n");
	*test = my_strjoin(*test, l);
}
