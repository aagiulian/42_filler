/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:23:24 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/10 19:51:38 by agiulian         ###   ########.fr       */
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
	int			change;
	char		**table;
	char		player;
	int			player_tot;
	int			*player_pos;
}				t_grid;

typedef struct	s_piece
{
	int			col;
	int			line;
	int			wldc_tot;
	int			wldc_x;
	int			wldc_y;
	char		**piece;
	int			pos_nb;
	int			*pos;
}				t_piece;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			score;
}				t_pos;

void			get_player(t_grid *grid, char **line);
void			get_grid_size(t_grid *grid, char **line);
void			get_piece_size(t_piece *piece, char **line);
void			get_piece(t_piece *piece, char **line);
void			delete_piece(t_piece *piece);
void			get_grid(t_grid *grid, char **line);
void			parse_piece_wldc(t_piece *piece);
int				put_piece(t_grid *grid, t_piece *piece, int wldc_nb);
int				*find_o_x(t_grid *grid, int nb, int *pos);
int				*find_pos(t_grid *grid, t_piece *piece);

#endif
