/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:48:35 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 08:50:36 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_fenv
{
	char	**lem_info;
	char	**room_name;
	char	**r_lnk;
	int		*room_passed;
	int		*link_used;
	int		num_room;
	int		n_lnk;
	int		nb_ants;
	int		color_ants;
	int		color_rooms;
	int		tour;
	int		nb_tour;
}				t_fenv;

typedef struct	s_check
{
	int		nb_start;
	int		nb_end;
	int		link;
	int		have_room;
	int		get_ants;
}				t_check;

typedef struct	s_fpath
{
	int		i;
	int		act_r;
	int		last_link;
}				t_fpath;

/*
** Parsing
*/
void			parse_nb_ants(t_fenv *fenv, t_check *check, char *line);
void			parse_map(t_fenv *fenv, t_check *check);
void			parse_room(t_fenv *fenv, t_check *check, char *first_line);
void			parse_link(t_fenv *f_e, t_check *check, char *line);
void			parse_option_l(t_fenv *fenv, t_check *check, char *line);
void			parse_color(t_fenv *fenv, char *line);
void			parse_start_and_end(t_fenv *fenv, t_check *check,
					char *first_line);

/*
** Check
*/
int				is_room_name(t_fenv *fenv, char *s);
int				is_fulldigit(char *str);
void			is_coord_ok(t_fenv *fenv, t_check *check, char **tab);
int				passed_in(t_fenv *fenv, int room);

/*
** Initialisation
*/
void			ini_var_fenv(t_fenv *fenv);
void			ini_var_check(t_check *check);
void			ini_room_passed(t_fenv *fenv);
void			ini_link_used(t_fenv *fenv);

/*
** Tools
*/
char			**extend_tab_room(t_fenv *fenv);
char			**extend_tab_link(t_fenv *fenv);
char			**remove_tab_link(t_fenv *fenv, int room);
void			clean_useless(t_fenv *fenv);
void			print_lem_info(t_fenv *fenv);
void			print_result(t_fenv *fenv, t_fpath *fp, int n_ant);
void			parse_tour(t_fenv *fenv, char *line);

/*
** Errors
*/
void			ft_error(t_fenv *fenv, t_check *check);
void			ft_error_ant(void);
void			ft_error_algo(t_fenv *fenv);

/*
**	Algo
*/
int				n_next_room(t_fenv *fenv, char *next_room);
void			go_to_next_room(t_fenv *fenv, t_fpath *fp, char *lk_split,
				int nb);
void			find_path(t_fenv *f, t_fpath *fp);
void			take_path(t_fenv *f, int n_ant);
void			move_ants(t_fenv *fenv);
void			do_algo(t_fenv *fenv);

#endif
