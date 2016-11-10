/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 17:03:36 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 08:37:40 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ini_var_fenv(t_fenv *fenv)
{
	fenv->lem_info = (char **)malloc(sizeof(char *) * 1);
	fenv->lem_info[0] = NULL;
	fenv->r_lnk = (char **)malloc(sizeof(char *) * 1);
	fenv->r_lnk[0] = NULL;
	fenv->room_name = (char **)malloc(sizeof(char *) * 3);
	fenv->room_name[0] = NULL;
	fenv->room_name[1] = NULL;
	fenv->room_name[2] = NULL;
	fenv->num_room = 2;
	fenv->n_lnk = 0;
	fenv->nb_ants = 0;
	fenv->color_ants = 0;
	fenv->color_rooms = 0;
	fenv->tour = 0;
	fenv->nb_tour = 0;
}

void	ini_var_check(t_check *check)
{
	check->nb_start = 0;
	check->nb_end = 0;
	check->link = 0;
	check->have_room = 0;
	check->get_ants = 0;
}

void	ini_room_passed(t_fenv *fenv)
{
	int	i;

	i = 0;
	fenv->room_passed = (int*)malloc(sizeof(int) * fenv->num_room);
	fenv->room_passed[0] = 1;
	while (i < fenv->num_room)
	{
		fenv->room_passed[i] = 0;
		i++;
	}
}

void	ini_link_used(t_fenv *fenv)
{
	int	i;

	i = 0;
	fenv->link_used = (int*)malloc(sizeof(int) * fenv->n_lnk);
	while (i < fenv->n_lnk)
	{
		fenv->link_used[i] = 0;
		i++;
	}
}
