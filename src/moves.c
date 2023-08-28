/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:03:18 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/18 12:03:18 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_collectible(t_vars *vars, int row, int col)
{
	char	*current;

	if (vars->map[row][col] == 'C')
	{
		current = vars->map[row];
		current[col] = '0';
		free(vars->map[row]);
		vars->map[row] = ft_strdup(current);
		vars->map[row][col] = '0';
		vars->current_c++;
	}
}

static int	exit_program(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->textures->cd);
	mlx_destroy_image(vars->mlx, vars->textures->csa);
	mlx_destroy_image(vars->mlx, vars->textures->csc);
	mlx_destroy_image(vars->mlx, vars->textures->ch);
	mlx_destroy_image(vars->mlx, vars->textures->e);
	mlx_destroy_image(vars->mlx, vars->textures->p);
	mlx_destroy_image(vars->mlx, vars->textures->s);
	mlx_destroy_image(vars->mlx, vars->textures->w);
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	free_array(vars->map);
	free_texture(vars->textures);
	exit (0);
}

static int	next_frame(int keycode, t_vars *vars)
{
	fill_last_position(vars, vars->pos.x, vars->pos.y);
	next_move(vars, keycode);
	if (keycode == 65307 || (vars->map[vars->pos.y \
		/ 64][vars->pos.x / 64] == 'E' && vars->num_c == vars->current_c))
		exit_program(vars);
	is_collectible(vars, vars->pos.y / 64, vars->pos.x / 64);
	mlx_put_image_to_window(vars->mlx, vars->win, \
		vars->textures->p, vars->pos.x, vars->pos.y);
	return (0);
}

void	moves(t_vars *vars)
{
	ft_printf("\n");
	mlx_expose_hook(vars->win, fill_map, vars);
	mlx_hook(vars->win, 17, 0L, exit_program, vars);
	mlx_key_hook(vars->win, next_frame, vars);
	mlx_loop(vars->mlx);
}
