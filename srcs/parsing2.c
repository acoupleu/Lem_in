/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 06:49:42 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 09:49:25 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	parse_option_l(t_fenv *fenv, t_check *check, char *line)
{
	if (line[2] && (line[2] == 's' || line[2] == 'e') && check->get_ants == 1)
		parse_start_and_end(fenv, check, line);
	else if (line[2] && line[2] == 'c')
		parse_color(fenv, line);
	else if (line[2] && line[2] == 'n')
		parse_tour(fenv, line);
	else
		fenv->lem_info = ft_tab_extend(fenv->lem_info, line);
}

void	parse_color(t_fenv *fenv, char *line)
{
	if (ft_strcmp(line, "##color ants") == 0)
		fenv->color_ants = 1;
	else if (ft_strcmp(line, "##color rooms") == 0)
		fenv->color_rooms = 1;
	fenv->lem_info = ft_tab_extend(fenv->lem_info, line);
}

void	parse_tour(t_fenv *fenv, char *line)
{
	if (ft_strcmp(line, "##nb tours") == 0)
		fenv->tour = 1;
	fenv->lem_info = ft_tab_extend(fenv->lem_info, line);
}
