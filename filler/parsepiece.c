/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsepiece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 13:19:08 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/20 13:54:58 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parse_piece_wldc(t_piece *piece)
{
	int i;
	int j;

	i = 0;
	piece->wldc_tot = 0;
	while (i < piece->line)
	{
		j = 0;
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
				piece->wldc_tot++;
			j++;
		}
		i++;
	}
}

void	get_piece_xy_minmax(t_piece *piece, int pos)
{
	if (pos / piece->col < piece->xmin)
		piece->xmin = pos / piece->col;
	if (pos / piece->col > piece->xmax)
		piece->xmax = pos / piece->col;
	if (pos % piece->col < piece->ymin)
		piece->ymin = pos % piece->col;
	if (pos % piece->col > piece->ymax)
		piece->ymax = pos % piece->col;
}

void	get_piece_width_height(t_piece *piece)
{
	int i;
	int	j;
	int	pos;

	pos = 0;
	i = 0;
	piece->xmin = piece->line;
	piece->xmax = 0;
	piece->ymin = piece->col;
	piece->ymax = 0;
	while (piece->piece[i])
	{
		j = 0;
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
				get_piece_xy_minmax(piece, pos);
			pos++;
			j++;
		}
		i++;
	}
	piece->width = piece->ymax - piece->ymin + 1;
	piece->height = piece->xmax - piece->xmin + 1;
}

void	simplify_piece(t_piece *piece)
{
	int	i;
	int	j;

	i = piece->xmin;
	j = 0;
	piece->edited = (char**)malloc(sizeof(char*) * piece->height + 1);
	while (i <= piece->xmax)
	{
		piece->edited[j] = ft_strndup(piece->piece[i] + piece->ymin, \
				piece->width);
		j++;
		i++;
	}
	piece->edited[j] = NULL;
	i = -1;
}
