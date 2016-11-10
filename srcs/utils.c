/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:34:36 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 07:59:19 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	**extend_tab_room(t_fenv *fenv)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = (char **)malloc(sizeof(char *) * (fenv->num_room + 2));
	while (i < fenv->num_room)
	{
		if (fenv->room_name[i])
			new_tab[i] = fenv->room_name[i];
		i++;
	}
	new_tab[fenv->num_room + 1] = NULL;
	return (new_tab);
}

char	**extend_tab_link(t_fenv *fenv)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = (char **)malloc(sizeof(char *) * (fenv->n_lnk + 2));
	while (i < fenv->n_lnk)
	{
		if (fenv->r_lnk[i])
			new_tab[i] = fenv->r_lnk[i];
		i++;
	}
	new_tab[fenv->n_lnk + 1] = NULL;
	return (new_tab);
}

char	**remove_tab_link(t_fenv *fenv, int room)
{
	char	**new_tab;
	int		*l_used;
	int		i;

	i = 0;
	new_tab = (char **)malloc(sizeof(char *) * (fenv->n_lnk + 1));
	l_used = (int *)malloc(sizeof(int) * (fenv->n_lnk));
	while (i < room && i < fenv->n_lnk)
	{
		new_tab[i] = fenv->r_lnk[i];
		l_used[i] = fenv->link_used[i];
		i++;
	}
	i++;
	while (i < fenv->n_lnk)
	{
		new_tab[i - 1] = fenv->r_lnk[i];
		l_used[i - 1] = fenv->link_used[i];
		i++;
	}
	fenv->link_used = l_used;
	fenv->n_lnk--;
	new_tab[fenv->n_lnk] = NULL;
	return (new_tab);
}

void	clean_useless(t_fenv *fenv)
{
	int	i;

	i = 0;
	while (i < fenv->n_lnk)
	{
		if (fenv->link_used[i] == 0)
		{
			fenv->r_lnk = remove_tab_link(fenv, i);
			i = 0;
		}
		i++;
	}
}

void	print_result(t_fenv *fenv, t_fpath *fp, int n_ant)
{
	if (fenv->color_ants == 1)
	{
		if (fenv->color_rooms == 1)
			ft_printf("\033[1;3%dmL%d\033[00m-\033[0;31m%s\n", (n_ant % 7),
			n_ant, fenv->room_name[fp->act_r]);
		else
			ft_printf("\033[1;3%dmL%d\033[00m-%s\n", n_ant % 7, n_ant,
			fenv->room_name[fp->act_r]);
	}
	else
	{
		if (fenv->color_rooms == 1)
			ft_printf("\033[1;37mL%d-\033[0;31m%s\n", n_ant,
			fenv->room_name[fp->act_r]);
		else
			ft_printf("L%d-%s\n", n_ant, fenv->room_name[fp->act_r]);
	}
}
