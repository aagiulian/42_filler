/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:50:32 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/08 17:21:15 by agiulian         ###   ########.fr       */
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
	int		nb;
	int		*pos;

	i = 0;
	pos = malloc(sizeof(int) * 2);
	fd = open("test", O_RDWR); // DEBUG
	dup2(fd, 2);	// DEBUG

	grid = malloc(sizeof(t_grid));
	piece = malloc(sizeof(t_piece));
	grid->table = NULL;
	get_player(grid, &line);
	ft_putendl_fd(line, fd);
	ft_putendl_fd(line, fd);
	ft_putnbr_fd(grid->line, fd);
	ft_putendl_fd("", fd);
	ft_putnbr_fd(grid->col, fd);
	ft_putendl_fd("", fd);
	grid->change = 0;
	while (get_next_line(0, &line) == 1)
	{
		i = 0;
		ft_putstr_fd("line =", fd);
		get_grid_size(grid, &line);
		ft_putendl_fd(line, fd);
		ft_putstr_fd("lol", 2);
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
		i = 1;
		parse_piece_wldc(piece);
		pos = find_o_x(grid, i, pos);
		while (put_piece(piece, grid, pos, 1) == 0)
		{
			if (grid->change == 1)
				exit (0);
			i++;
			pos = find_o_x(grid, i, pos);
		}
		ft_printf("%i %i\n", pos[0], pos[1]);
		delete_piece(piece);
	}
	return (0);
}
