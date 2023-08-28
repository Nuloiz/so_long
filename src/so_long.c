/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:37:50 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/21 15:01:09 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	getting_vars_values(char **argv, t_vars *vars)
{
	int		size;
	int		length;

	size = 0;
	length = 0;
	vars->mov_count = 0;
	vars->current_c = 0;
	vars->map = read_map(argv[1]);
	if (!vars->map)
		return (0);
	while (vars->map[size] != NULL)
	{
		length = (int)ft_strlen(vars->map[size]);
		size++;
	}
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, length * 64, size * 64, "so_long");
	return (1);
}

static int	ending_ber(char *name)
{
	size_t	len;

	len = ft_strlen(name) - 1;
	if (name[len] != 'r' || name[len - 1] != 'e' || \
		name[len - 2] != 'b' || name[len - 3] != '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int		num_of_c;
	t_vars	vars;

	if (argc <= 1 || argc >= 3)
		return (0);
	if (ending_ber(argv[1]) == 0)
		return (ft_printf("Error\nInvalid Map"));
	if (!getting_vars_values(argv, &vars))
		return (0);
	num_of_c = start_screen(&vars);
	if (num_of_c == 0)
	{
		mlx_destroy_window(vars.mlx, vars.win);
		free_array(vars.map);
		free(vars.mlx);
		return (ft_printf("Error\nInvalid Map"));
	}
	moves(&vars);
	return (0);
}
