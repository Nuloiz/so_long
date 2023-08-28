/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:53:53 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/14 11:53:53 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_vars *vars)
{
	vars->pos.y = vars->pos.y - 64;
	vars->mov_count++;
	ft_printf("\033[A%i Moves\n", vars->mov_count);
}

static void	move_down(t_vars *vars)
{
	vars->pos.y = vars->pos.y + 64;
	vars->mov_count++;
	ft_printf("\033[A%i Moves\n", vars->mov_count);
}

static void	move_left(t_vars *vars)
{
	vars->pos.x = vars->pos.x - 64;
	vars->mov_count++;
	ft_printf("\033[A%i Moves\n", vars->mov_count);
}

static void	move_right(t_vars *vars)
{
	vars->pos.x = vars->pos.x + 64;
	vars->mov_count++;
	ft_printf("\033[A%i Moves\n", vars->mov_count);
}

void	next_move(t_vars *vars, int keycode)
{
	if (keycode == 119 && vars->map[(vars->pos.y - 64) / 64] \
			[vars->pos.x / 64] != '1')
		move_up(vars);
	else if (keycode == 97 && vars->map[vars->pos.y / 64] \
			[(vars->pos.x - 64) / 64] != '1')
		move_left(vars);
	else if (keycode == 115 && vars->map[(vars->pos.y + 64) / 64] \
			[vars->pos.x / 64] != '1')
		move_down(vars);
	else if (keycode == 100 && vars->map[vars->pos.y / 64] \
			[(vars->pos.x + 64) / 64] != '1')
		move_right(vars);
}
