/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:50:32 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/20 13:47:12 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	init_grid_and_piece(t_grid **grid, t_piece **piece)
{
	if (!(*grid = malloc(sizeof(t_grid))))
		exit(0);
	if (!(*piece = malloc(sizeof(t_piece))))
		exit(0);
	if (!((*piece)->pos = malloc(sizeof(int) * 2)))
		exit(0);
	(*grid)->table = NULL;
	(*grid)->dir = 1;
}

int			main(void)
{
	t_grid	*grid;
	t_piece *piece;
	char	*line;
	int		*pos;

	grid = NULL;
	piece = NULL;
	if (!(pos = malloc(sizeof(int) * 2)))
		return (0);
	init_grid_and_piece(&grid, &piece);
	get_player(grid, &line);
	while (get_next_line(0, &line) == 1)
	{
		get_grid_size(grid, &line);
		get_grid(grid, &line);
		get_piece(piece, &line);
		simplify_piece(piece);
		parse_piece_wldc(piece);
		if (!(pos = find_pos(grid, piece)))
			return (0);
		else
			ft_printf("%i %i\n", pos[0], pos[1]);
		delete_piece(piece);
	}
	return (0);
}
