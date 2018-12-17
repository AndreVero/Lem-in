/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averemiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 14:24:30 by averemiy          #+#    #+#             */
/*   Updated: 2018/06/11 15:10:21 by averemiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/libft.h"
# include "get_next_line.h"
# include "./libft/libft.h"

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	t_list			*neib;
	int				checked;
	int				number;
	int				check_prev;
	int				start;
	struct s_room	*end;
	struct s_room	*prev;
	struct s_room	*next;
}					t_room;

typedef struct		s_ant
{
	int				number;
	struct s_ant	*next;
}					t_ant;

typedef struct		s_way
{
	int				ant;
	struct s_way	*next;
	char			*name;
	struct s_way	*prev;
}					t_way;

typedef struct		s_all
{
	t_room			*end;
	t_room			*tmp;
}					t_all;

void				find_neighbors(char *l, t_room *t);
t_room				*create_start(t_room *t, int fd, char **test);
void				create_new_room(char *l, t_room **t);
t_room				*create_end(int fd, char **test);
void				add_end(t_room *t, t_room *end);
void				free_2d(char **str, int i);
int					solver(int ants, t_room *t, t_room *end, char *test);
int					check_valid(t_room *t, t_room *end, int ants);
void				find_the_short_way(int ants, t_room *end);
t_ant				*find_last(t_ant *t);
int					find_step_of_ant(t_way *t);
int					way_check_zero(t_way *way);
void				free_way(t_way *way);
void				free_room(t_room *room);
char				*my_strjoin(char *s1, char *s2);
int					check_rooms(char *str);
int					check_links(char *str);
int					read_from_output(char **test, t_all **r, int *a, char *l);
int					check_all(char **str, char *l, t_all *rooms, int ants);
char				*ft_check_str(char **str, char *l);
void				print_way(t_way *way);
int					check_start(t_room **tmp);
int					check_comm(char *l);
int					create_comm(char **str, char *l);
int					not_valid(t_all *r);
void				create_ant_after_comm(char **test, char *l);
int					check_end(t_room *t);
int					all_checked(t_room *t);
int					find_end(t_room *end);
int					no_way(t_room *t, t_room *end);

#endif
