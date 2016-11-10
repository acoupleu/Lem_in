/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 02:23:03 by acoupleu          #+#    #+#             */
/*   Updated: 2016/10/01 03:34:32 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_error(t_fenv *fenv, t_check *check)
{
	if (check->have_room == 1 && check->link == 1)
		ft_error_algo(fenv);
	else
	{
		ft_printf("MAP ERROR");
		exit(0);
	}
}

void	ft_error_ant(void)
{
	ft_printf("INVALID ANTS NUMBER");
	exit(0);
}

void	ft_error_algo(t_fenv *fenv)
{
	do_algo(fenv);
	exit(0);
}
