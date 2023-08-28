/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:11:45 by nschutz           #+#    #+#             */
/*   Updated: 2023/07/27 10:56:41 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <math.h>
# include "../tools/minilibx-linux/mlx_int.h"
# include "../tools/minilibx-linux/mlx.h"
# include "../tools/libft/libft.h"

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

typedef struct s_texture
{
	void	*p;
	void	*w;
	void	*s;
	void	*e;
	void	*cd;
	void	*csa;
	void	*csc;
	void	*ch;
}				t_texture;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	t_texture	*textures;
	int			num_c;
	int			current_c;
	int			mov_count;
	t_pos		pos;

}				t_vars;

int		main(int argc, char **argv);
void	moves(t_vars *vars);
char	**read_map(char *argv);
int		map_length(char *name);
int		map_first_line(char **map);
int		map_last_line(char **map, int length);
int		map_check_line(int line, char *map, int length);
int		is_ep_true(char *map, char c);
int		map_check_path(char **map);
int		fill_map(t_vars *vars);
void	fill_last_position(t_vars *vars, int col, int row);
int		start_screen(t_vars *vars);
char	**dup_map(char **map);
int		number_of_collectibles(char	**map);
int		startposition_row(char **map);
int		startposition_col(char **map);
void	next_move(t_vars *vars, int keycode);
void	free_array(char **array);
void	free_texture(t_texture *texture);

#endif