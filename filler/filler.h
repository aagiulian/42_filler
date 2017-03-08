/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:23:24 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/08 11:49:39 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft/includes/get_next_line.h"

typedef struct	s_grid
{
	int			col;
	int			line;
	char		**table;
	char		player;
}				t_grid;

typedef struct	s_piece
{
	int			col;
	int			line;
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
	char		**piece;
}				t_piece;

void			get_player(t_grid *grid, char **line);
void			get_grid_size(t_grid *grid, char **line);
void			get_piece_size(t_piece *piece, char **line);
void			get_piece(t_piece *piece, char **line);
void			get_grid(t_grid *grid, char **line);

#endif
