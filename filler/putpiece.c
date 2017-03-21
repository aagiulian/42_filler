/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:01:13 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/20 14:19:19 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		delete_piece(t_piece *piece)
{
	int i;

	i = 0;
	while (i < piece->line)
	{
		ft_strdel(&piece->piece[i]);
		i++;
	}
	ft_tabdel(&piece->piece);
}

static int	check(t_piece *piece, t_grid *grid)
{
	if (grid->link)
	{
		if (grid->dir == 2)
		{
			piece->pos[0] = grid->pos / (grid->col) - piece->xmin;
			piece->pos[1] = grid->pos % (grid->col) - piece->ymin;
		}
		else
		{
			piece->pos[0] = grid->pos / (grid->col) - piece->xmax;
			piece->pos[1] = grid->pos % (grid->col) - piece->ymax;
		}
		return (1);
	}
	else
		return (0);
}

int			put_piece(t_grid *grid, t_piece *piece)
{
	int i;
	int j;

	i = 0;
	grid->link = 0;
	while (piece->edited[i])
	{
		j = 0;
		while (piece->edited[i][j])
		{
			if (piece->edited[i][j] == '*')
			{
				if (!grid->link && grid->table[grid->pos / (grid->col) +
						i][grid->pos % (grid->col) + j] == grid->player)
					grid->link = 1;
				else if (grid->table[grid->pos / (grid->col) + i][grid->pos % \
						(grid->col) + j] != '.')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (check(piece, grid));
}

int			put_piece_reverse(t_grid *grid, t_piece *piece)
{
	int i;
	int j;

	grid->link = 0;
	i = piece->height - 1;
	while (i >= 0)
	{
		j = piece->width - 1;
		while (j >= 0)
		{
			if (piece->edited[i][j] == '*')
			{
				if (!grid->link && grid->table[grid->pos / (grid->col) - \
	piece->height + 1 + i][grid->pos % (grid->col) - piece->width + 1 + j] \
	== grid->player)
					grid->link = 1;
				else if (grid->table[grid->pos / (grid->col) - piece->height + \
				1 + i][grid->pos % (grid->col) - piece->width + 1 + j] != '.')
					return (0);
			}
			j--;
		}
		i--;
	}
	return (check(piece, grid));
}
