/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 13:36:01 by nschutz           #+#    #+#             */
/*   Updated: 2023/08/11 13:36:01 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_vars	*filling_texture(t_vars *vars)
{
	int			size;

	vars->textures = malloc(sizeof(t_texture));
	vars->textures->cd = mlx_xpm_file_to_image \
		(vars->mlx, "textures/Col_Drill.xpm", &size, &size);
	vars->textures->csa = mlx_xpm_file_to_image \
		(vars->mlx, "textures/Col_Sandwich.xpm", &size, &size);
	vars->textures->csc = mlx_xpm_file_to_image \
		(vars->mlx, "textures/Col_W&S.xpm", &size, &size);
	vars->textures->ch = mlx_xpm_file_to_image \
		(vars->mlx, "textures/Col_Hammer.xpm", &size, &size);
	vars->textures->e = mlx_xpm_file_to_image \
			(vars->mlx, "textures/Exit_TB.xpm", &size, &size);
	vars->textures->p = mlx_xpm_file_to_image \
		(vars->mlx, "textures/Char.xpm", &size, &size);
	vars->textures->s = mlx_xpm_file_to_image \
		(vars->mlx, "textures/Space.xpm", &size, &size);
	vars->textures->w = mlx_xpm_file_to_image \
		(vars->mlx, "textures/Wall_MB2.xpm", &size, &size);
	return (vars);
}

int	start_screen(t_vars *vars)
{
	vars->pos.y = startposition_row(vars->map) * 64;
	vars->pos.x = startposition_col(vars->map) * 64;
	vars = filling_texture(vars);
	vars->num_c = number_of_collectibles(vars->map);
	if (vars->num_c < 1)
		return (0);
	fill_map(vars);
	return (1);
}
