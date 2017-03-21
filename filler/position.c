/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:53:55 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/20 14:16:49 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_pos_from_start(t_grid *grid, t_piece *piece, int pos)
{
	int	i;
	int	j;

	i = pos / grid->col;
	j = pos % grid->col;
	while (i <= grid->line)
	{
		while (j <= grid->col)
		{
			if (i + piece->height <= grid->line && j + piece->width \
					<= grid->col)
			{
				grid->pos1 = i * grid->col + j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		get_pos_from_start_rev(t_grid *grid, t_piece *piece, int pos)
{
	int	i;
	int	j;

	i = pos / grid->col;
	j = pos % grid->col;
	while (i <= grid->line)
	{
		while (j >= 0)
		{
			if (i + piece->height <= grid->line && j + piece->width <= \
					grid->col)
			{
				grid->pos1 = i * grid->col + j;
				return (1);
			}
			j--;
		}
		j = grid->col - 1;
		i++;
	}
	return (0);
}

int		get_pos_from_end(t_grid *grid, t_piece *piece, int pos)
{
	int	i;
	int	j;

	i = pos / grid->col;
	j = pos % grid->col;
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (i - piece->height + 1 >= 0 && j - piece->width + 1 >= 0)
			{
				grid->pos2 = i * grid->col + j;
				return (1);
			}
			j--;
		}
		j = grid->col - 1;
		i--;
	}
	return (0);
}

int		find_pos_dir_one(t_grid *grid, t_piece *piece)
{
	grid->dir = 2;
	grid->pos1 = 0;
	piece->pos_nb = 0;
	while ((grid->pos1 < grid->line * grid->col - 1) && \
			get_pos_from_start(grid, piece, grid->pos1))
	{
		grid->pos = grid->pos1;
		if (put_piece(grid, piece))
			return (1);
		grid->pos1++;
	}
	return (0);
}

int		find_pos_dir_three(t_grid *grid, t_piece *piece)
{
	grid->dir = 2;
	grid->pos1 = grid->col - 1;
	piece->pos_nb = 0;
	while ((grid->pos1 < grid->line * grid->col - 1) && \
			get_pos_from_start_rev(grid, piece, grid->pos1))
	{
		grid->pos = grid->pos1;
		if (put_piece(grid, piece))
			return (1);
		if (grid->pos1 % grid->col == 0)
			grid->pos1 += grid->col * 2 - 2;
		else
			grid->pos1--;
	}
	return (0);
}

int		find_pos_dir_two(t_grid *grid, t_piece *piece)
{
	grid->dir = 1;
	piece->pos_nb = 0;
	grid->pos2 = grid->col * grid->line - 1;
	while (grid->pos2 >= 0 && get_pos_from_end(grid, piece, grid->pos2))
	{
		grid->pos = grid->pos2;
		if (put_piece_reverse(grid, piece))
			return (1);
		grid->pos2--;
	}
	return (0);
}

int		*find_pos(t_grid *grid, t_piece *piece)
{
	int		*pos;
	int		ret;

	pos = malloc(sizeof(int) * 2);
	ret = 0;
	if (grid->dir == 1)
		ret = find_pos_dir_three(grid, piece);
	else if (grid->dir == 2)
		ret = find_pos_dir_two(grid, piece);
	if (ret)
	{
		pos[0] = piece->pos[0];
		pos[1] = piece->pos[1];
		return (pos);
	}
	else
		return (NULL);
}
