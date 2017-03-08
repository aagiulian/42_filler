/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:50:32 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/08 11:51:56 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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
	i = 0;
	while (i < piece->line)
	{
		ft_putendl_fd(piece->piece[i], fd);
		i++;
	}
	return (0);
}
