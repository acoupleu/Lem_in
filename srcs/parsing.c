/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:57:26 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 09:25:37 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	parse_map(t_fenv *fenv, t_check *check)
{
	char	*line;

	line = NULL;
	parse_nb_ants(fenv, check, line);
	if (check->get_ants == 0)
		ft_error(fenv, check);
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] == '#')
			parse_option_l(fenv, check, line);
		else if (ft_strchr(line, '-') == NULL && line[0] != '#')
			parse_room(fenv, check, line);
		else if (ft_strchr(line, '-') != NULL && line[0] != '#')
			parse_link(fenv, check, line);
		else if (line[0] == '\0')
			break ;
		else
			fenv->lem_info = ft_tab_extend(fenv->lem_info, line);
	}
	if (fenv->r_lnk[0] == NULL)
		ft_error(fenv, check);
	do_algo(fenv);
	exit(0);
}

void	parse_start_and_end(t_fenv *fenv, t_check *check, char *first_line)
{
	char	*line;
	char	**tmp_tab;

	line = first_line;
	get_next_line(0, &first_line);
	if (first_line[0] == '\0')
		ft_error(fenv, check);
	tmp_tab = ft_strsplit(first_line, ' ');
	if (ft_strcmp(line, "##start") == 0 && tmp_tab != NULL)
	{
		fenv->room_name[0] = tmp_tab[0];
		check->nb_start++;
		check->have_room = 1;
	}
	else if (ft_strcmp(line, "##end") == 0 && tmp_tab != NULL)
	{
		fenv->room_name[1] = tmp_tab[0];
		check->nb_end++;
		check->have_room = 1;
	}
	is_coord_ok(fenv, check, tmp_tab);
	fenv->lem_info = ft_tab_extend(fenv->lem_info, line);
	fenv->lem_info = ft_tab_extend(fenv->lem_info, first_line);
	free(tmp_tab);
}

void	parse_room(t_fenv *fenv, t_check *check, char *first_line)
{
	char	**tmp_tab;

	tmp_tab = ft_strsplit(first_line, ' ');
	if (tmp_tab[3] != NULL && check->link == 0)
		ft_error(fenv, check);
	else if (check->link == 1)
		ft_error_algo(fenv);
	is_coord_ok(fenv, check, tmp_tab);
	fenv->room_name = extend_tab_room(fenv);
	fenv->room_name[fenv->num_room] = tmp_tab[0];
	(fenv->num_room)++;
	check->have_room = 1;
	fenv->lem_info = ft_tab_extend(fenv->lem_info, first_line);
	free(tmp_tab);
}

void	parse_link(t_fenv *f_e, t_check *check, char *line)
{
	char	**tmp_tab;

	if (check->have_room == 0)
		ft_error(f_e, check);
	if (ft_count_char(line, '-') != 1 && check->link == 0)
		ft_error(f_e, check);
	else if (ft_count_char(line, '-') != 1)
		ft_error_algo(f_e);
	tmp_tab = ft_strsplit(line, '-');
	check->link = 1;
	if (tmp_tab[2] != NULL || !is_room_name(f_e, tmp_tab[0])
		|| !is_room_name(f_e, tmp_tab[1]))
		ft_error_algo(f_e);
	f_e->r_lnk = extend_tab_link(f_e);
	f_e->r_lnk[f_e->n_lnk] = (char *)malloc(sizeof(char) * ft_strlen(line) + 1);
	f_e->r_lnk[f_e->n_lnk] = line;
	(f_e->n_lnk)++;
	f_e->lem_info = ft_tab_extend(f_e->lem_info, line);
	free(tmp_tab);
}

void	parse_nb_ants(t_fenv *fenv, t_check *check, char *line)
{
	while (get_next_line(0, &line))
	{
		if (line[0] == '#' && line[1] == '#')
			parse_option_l(fenv, check, line);
		else if (is_fulldigit(line))
		{
			if (ft_strlen(line) > 10 || ft_atoi(line) <= 0)
				ft_error_ant();
			fenv->lem_info = ft_tab_extend(fenv->lem_info, line);
			fenv->nb_ants = ft_atoi(line);
			check->get_ants = 1;
			break ;
		}
		else if (line[0] == '#')
			fenv->lem_info = ft_tab_extend(fenv->lem_info, line);
		else
			break ;
	}
}
