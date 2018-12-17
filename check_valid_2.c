/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:14:52 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/09 14:01:44 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	next_link_check(char *str)
{
	if (ft_strlen(str) > 1)
		if (str[0] == 'L' || str[0] == 'L')
			return (1);
	if (ft_strstr(str, " "))
		return (1);
	return (0);
}

int			check_links(char *str)
{
	int		i;

	i = 0;
	if (next_link_check(str))
		return (1);
	while (str[i] != '\0' && str[i] != '-')
		i++;
	if (str[i] != '-')
		return (1);
	i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0')
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int			next_check_room(char *str)
{
	if (ft_strlen(str) > 1)
		if (str[0] == '#' || str[0] == 'L')
			return (1);
	if (ft_strstr(str, "-"))
		return (1);
	return (0);
}

int			check_rooms(char *str)
{
	int		i;

	i = 0;
	if (next_check_room(str))
		return (1);
	while (str[i] != '\0' && str[i] != ' ')
		i++;
	if (str[i] != ' ')
		return (1);
	i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0' && str[i] != ' ' && ft_isdigit(str[i]))
		i++;
	if (str[i] != ' ')
		return (1);
	i++;
	if (str[i] == '\0')
		return (1);
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

char		*my_strjoin(char *s1, char *s2)
{
	int		j;
	char	*cat;

	if (!s1)
		j = ft_strlen(s2);
	else
		j = ft_strlen(s1) + ft_strlen(s2);
	cat = (char *)malloc(sizeof(char) * (j + 2));
	ft_strcpy(cat, s1);
	ft_strcat(cat, s2);
	free(s1);
	cat[j + 1] = '\0';
	return (cat);
}
