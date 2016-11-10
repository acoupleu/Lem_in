/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 17:41:28 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 03:33:55 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	is_coord_ok(t_fenv *fenv, t_check *check, char **tab)
{
	if (tab[1] && tab[2])
	{
		if (!is_fulldigit(tab[1]) || !is_fulldigit(tab[2])
		|| tab[3])
			ft_error(fenv, check);
	}
	else
		ft_error(fenv, check);
}

int		is_room_name(t_fenv *fenv, char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < (fenv->num_room + 1))
	{
		if (fenv->room_name[i])
		{
			if (ft_strcmp(fenv->room_name[i], s) == 0)
				count++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	else
		return (0);
}

int		is_fulldigit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int		passed_in(t_fenv *fenv, int room)
{
	if (fenv->room_passed[room] == 1)
		return (1);
	else
		return (0);
}
