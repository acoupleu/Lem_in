/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 21:01:37 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 08:19:25 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		n_next_room(t_fenv *fenv, char *next_room)
{
	int	i;

	i = 0;
	while (ft_strcmp(next_room, fenv->room_name[i]) != 0)
		i++;
	return (i);
}

void	go_to_next_room(t_fenv *fenv, t_fpath *fp, char *lk_split, int nb)
{
	if (nb == 1)
	{
		fenv->room_passed[fp->act_r] = 1;
		fp->act_r = n_next_room(fenv, lk_split);
		fp->last_link = fp->i;
		fenv->link_used[fp->i] = 1;
		fp->i = -1;
	}
	else
	{
		fenv->room_passed[fp->act_r] = 1;
		fp->act_r = n_next_room(fenv, lk_split);
		fp->last_link = fp->i;
		fenv->link_used[fp->i] = 1;
		fp->i = -1;
	}
}

void	find_path(t_fenv *f, t_fpath *fp)
{
	char	**link_split;

	link_split = ft_strsplit(f->r_lnk[fp->i], '-');
	if (ft_strcmp(link_split[0], f->room_name[fp->act_r]) == 0
		&& f->link_used[fp->i] == 0 && fp->act_r != 1)
	{
		go_to_next_room(f, fp, link_split[1], 1);
	}
	else if (ft_strcmp(link_split[1], f->room_name[fp->act_r]) == 0
		&& f->link_used[fp->i] == 0 && fp->act_r != 1)
	{
		go_to_next_room(f, fp, link_split[0], 0);
	}
	if (passed_in(f, fp->act_r) || (fp->i == (f->n_lnk - 1) && fp->act_r != 1))
	{
		f->r_lnk = remove_tab_link(f, fp->last_link);
		fp->last_link = 0;
		fp->i = -1;
		fp->act_r = 0;
		ini_room_passed(f);
		ini_link_used(f);
	}
}

void	take_path(t_fenv *f, int n_ant)
{
	t_fpath	fp;
	char	**link_split;

	fp.i = 0;
	fp.act_r = 0;
	while (fp.i < f->n_lnk && !passed_in(f, 1) && fp.act_r != 1)
	{
		link_split = ft_strsplit(f->r_lnk[fp.i], '-');
		if (ft_strcmp(link_split[0], f->room_name[fp.act_r]) == 0
			&& f->link_used[fp.i] == 0)
		{
			go_to_next_room(f, &fp, link_split[1], 1);
			print_result(f, &fp, n_ant);
			f->nb_tour++;
		}
		else if (ft_strcmp(link_split[1], f->room_name[fp.act_r]) == 0
			&& f->link_used[fp.i] == 0)
		{
			go_to_next_room(f, &fp, link_split[0], 0);
			print_result(f, &fp, n_ant);
			f->nb_tour++;
		}
		fp.i++;
	}
}

void	do_algo(t_fenv *fenv)
{
	t_fpath	fp;

	fp.i = -1;
	fp.act_r = 0;
	ini_link_used(fenv);
	ini_room_passed(fenv);
	while ((fp.act_r != 1 || fenv->n_lnk != 0) && fenv->r_lnk[++fp.i])
	{
		find_path(fenv, &fp);
	}
	if (fenv->r_lnk[0] != NULL)
	{
		print_lem_info(fenv);
		move_ants(fenv);
		if (fenv->tour == 1)
		{
			ft_printf(
			"\033[1;37mLes fourmis ont finies detraverser en %d tours.\n",
			fenv->nb_tour);
		}
	}
	else
		ft_printf("No path found\n");
}
