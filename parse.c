/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:20:48 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/08 00:29:03 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_grid *grid, char **line)
{
	get_next_line(0, line);
	if ((*line)[10] == '1')
		grid->player = 'O';
	else
		grid->player = 'X';
	free(*line);
}

void	get_grid_size(t_grid *grid, char **line)
{
	char *str;

	get_next_line(0, line);
	str = *line + 8;
	grid->line = ft_atoi(str);
	while (*str != ' ')
		str++;
	grid->col = ft_atoi(str + 1);
	free(*line);
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
	free(*line);
}

void	get_piece(t_piece *piece, char **line)
{
	int	i;

	i = 0;
	get_piece_size(piece, line);
	piece->raw = NULL;
	while (i < piece->line)
	{
		get_next_line(0, line);
		piece->raw = ft_strjoin(piece->raw, *line);
		piece->raw = ft_strjoin(piece->raw, "\n");
		free(*line);
		i++;
	}
}

void	get_grid(t_grid *grid, char **line)
{
	int	i;

	i = 0;
	if (grid->table == NULL)
	{
		grid->table = (char**)malloc(sizeof(char*) * grid->line + 1);
		while (i < grid->line)
		{
			grid->table[i] = ft_strnew(grid->col);
			i++;
		}
		grid->table[i] = NULL;
	}
	i = 0;
	get_next_line(0, line);
	free(*line);
	while (i < grid->line)
	{
		get_next_line(0, line);
		ft_strcpy(grid->table[i], *line + 4);
		free(*line);
		i++;
	}
}

int		main(void)
{
	t_grid	*grid;
	t_piece *piece;
	char	*line;
	int		fd;
	int		i;

	i = 0;

	fd = open("test", O_RDWR); // DEBUG
	dup2(fd, 2);	// DEBUG

	grid = malloc(sizeof(t_grid));
	piece = malloc(sizeof(t_piece));
	grid->table = NULL;
	get_player(grid, &line);
	ft_putendl_fd(line, fd);
	get_grid_size(grid, &line);

	ft_putendl_fd(line, fd);
	ft_putnbr_fd(grid->line, fd);
	ft_putendl_fd("", fd);
	ft_putnbr_fd(grid->col, fd);
	ft_putendl_fd("", fd);
	get_grid(grid, &line);
	get_piece(piece, &line);
	while (i < grid->line)
	{
		ft_putendl_fd(grid->table[i], fd);
		i++;
	}
	ft_putendl_fd(piece->raw, fd);
	return (0);
}
