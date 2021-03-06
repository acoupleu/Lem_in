/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoupleu <acoupleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 21:31:56 by acoupleu          #+#    #+#             */
/*   Updated: 2016/05/31 19:04:13 by acoupleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse_flag2(const char *format, t_flag *flag, t_env *env)
{
	if (format[env->i] == '-')
		flag->minus = 1;
	else if (format[env->i] == '+')
		flag->plus = 1;
	else if (format[env->i] == ' ')
		flag->space = 1;
	else if (format[env->i] == 'z')
		flag->z = 1;
	else if (format[env->i] == '*')
		flag->etoile = 1;
}

void		parse_flag(const char *format, t_flag *flag, t_env *env)
{
	while (ft_strchr(env->conv, format[env->i]) == NULL)
	{
		if (format[env->i] == '0')
			flag->zero = 1;
		else if ('1' <= format[env->i] && format[env->i] <= '9')
			parse_size(format, flag, env);
		else if (format[env->i] == '.')
			parse_accuracy(format, flag, env);
		else if (format[env->i] == '#')
			flag->diese = 1;
		else if (format[env->i] == 'h')
			flag->h = (flag->h) + 1;
		else if (format[env->i] == 'j')
			flag->j = 1;
		else if (format[env->i] == 'l')
			flag->l = (flag->l) + 1;
		else
			parse_flag2(format, flag, env);
		(env->i)++;
	}
}

void		parse_size(const char *format, t_flag *flag, t_env *env)
{
	flag->size = ft_atoi(&format[env->i]);
	while ('0' <= format[env->i] && format[env->i] <= '9')
		(env->i)++;
	(env->i)--;
}

void		parse_accuracy(const char *format, t_flag *flag, t_env *env)
{
	(env->i)++;
	flag->acc = 0;
	if (!('0' < format[env->i] && format[env->i] <= '9'))
	{
		flag->acc = -1;
		(env->i)--;
		return ;
	}
	flag->acc = ft_atoi(&format[env->i]);
	while ('0' <= format[env->i] && format[env->i] <= '9')
		(env->i)++;
	(env->i)--;
}
