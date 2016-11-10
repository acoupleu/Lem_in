/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:22:21 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 08:50:59 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	print_lem_info(t_fenv *fenv)
{
	int i;

	i = 0;
	while (fenv->lem_info[i])
	{
		ft_printf("%s\n", fenv->lem_info[i]);
		i++;
	}
	ft_printf("\n");
}

void	move_ants(t_fenv *fenv)
{
	int i;

	i = 1;
	ini_room_passed(fenv);
	ini_link_used(fenv);
	while (i <= fenv->nb_ants)
	{
		take_path(fenv, i);
		ini_room_passed(fenv);
		ini_link_used(fenv);
		i++;
	}
}

int		main(void)
{
	t_fenv	fenv;
	t_check	check;

	ini_var_fenv(&fenv);
	ini_var_check(&check);
	parse_map(&fenv, &check);
	return (0);
}
