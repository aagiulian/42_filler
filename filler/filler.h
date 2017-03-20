/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:23:24 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/16 14:10:52 by agiulian         ###   ########.fr       */
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
	int			direction_1;
	int			pos1;
	int			direction_2;
	int			pos2;
	int			dir;
}				t_grid;

typedef struct	s_piece
{
	int			col;
	int			line;
	int			wldc_tot;
	int			wldc_x;
	int			wldc_y;
	char		**piece;
	char		**edited;
	int			pos_nb;
	int			*pos;
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
	int			width;
	int			height;
}				t_piece;

typedef struct	s_pos
{
	int			x;
	int			y;
	int			pos;
	int			score;
}				t_pos;

void			get_player(t_grid *grid, char **line);
void			get_grid_size(t_grid *grid, char **line);
void			get_piece_size(t_piece *piece, char **line);
void			get_piece(t_piece *piece, char **line);
void			delete_piece(t_piece *piece);
void			get_grid(t_grid *grid, char **line);
void			parse_piece_wldc(t_piece *piece);
int				put_piece(t_grid *grid, t_piece *piece);
int				put_piece_reverse(t_grid *grid, t_piece *piece);
int				*find_o_x(t_grid *grid, int nb, int *pos);
int				*find_pos(t_grid *grid, t_piece *piece);
void			find_best_pos(t_list *all_pos, int *pos);
void			find_all_possible_pos(t_grid *grid, t_piece *piece, \
		t_list **all_pos);
void			add_psbl_pos(t_list **all_pos, t_piece *piece, t_grid *grid);
void			get_player_pos(t_grid *grid);
void			get_pos_score(t_pos *pos, t_grid *grid);
void			get_enemy_start_pos(t_grid *grid);
void			get_piece_width_height(t_piece *piece);
void			simplify_piece(t_piece *piece);

#endif
