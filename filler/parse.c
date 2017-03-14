/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:20:48 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/11 18:59:21 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_enemy_start_pos(t_grid *grid)
{
	int	i;
	int	j;

	ft_putendl_fd("entree get enemy start", 2);
	i = 0;
	while (grid->table[i])
	{
		j = 0;
		while (grid->table[i][j])
		{
			if ((grid->player == 'O' && grid->table[i][j] == 'X') || \
				(grid->player == 'X' && grid->table[i][j] == 'O'))
				grid->enemy_start_pos = i * grid->col + j;
			j++;
		}
		i++;
	}
	ft_putendl_fd("sortie get enemy start", 2);
}

void	get_player(t_grid *grid, char **line)
{
	get_next_line(0, line);
	if ((*line)[10] == '1')
		grid->player = 'O';
	else
		grid->player = 'X';
	ft_strdel(line);
	//free(*line);
}

void	get_grid_size(t_grid *grid, char **line)
{
	char *str;

	str = *line + 8;
	grid->line = ft_atoi(str);
	while (*str != ' ')
		str++;
	grid->col = ft_atoi(str + 1);
	ft_strdel(line);
}

void	get_piece_size(t_piece *piece, char **line)
{
	char *str;

	get_next_line(0, line);
	str = *line + 6;
	piece->line = ft_atoi(str);
	while (*str != ' ')
		str++;
	piece->col = ft_atoi(str + 1);
	ft_strdel(line);
}

void	get_piece(t_piece *piece, char **line)
{
	int	i;

	i = 0;
	get_piece_size(piece, line);
	piece->piece = (char**)malloc(sizeof(char*) * (piece->line + 1));
	while (i < piece->line)
	{
		get_next_line(0, line);
		piece->piece[i] = ft_strdup(*line);
		ft_strdel(line);
		i++;
	}
	piece->piece[i] = NULL;
}

void	get_grid(t_grid *grid, char **line)
{
	int	i;

	i = 0;
	if (grid->table == NULL)
		grid->table = (char**)malloc(sizeof(char*) * grid->line + 1);
	i = 0;
	get_next_line(0, line);
	ft_strdel(line);
	while (i < grid->line)
	{
		get_next_line(0, line);
		grid->table[i] = ft_strdup(*line + 4);
		ft_strdel(line);
		i++;
	}
	grid->table[i] = NULL;
}
