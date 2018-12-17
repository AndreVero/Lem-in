/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 17:55:43 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/06 18:00:21 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		print_way(t_way *way)
{
	while (way->next != NULL)
		way = way->next;
	while (way != NULL)
	{
		if (way->ant > 0)
		{
			write(1, "L", 1);
			ft_putnbr(way->ant);
			write(1, "-", 1);
			ft_putstr(way->name);
			write(1, " ", 1);
		}
		way = way->prev;
	}
	write(1, "\n", 1);
}
