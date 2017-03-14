/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:01:13 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/11 21:42:40 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	delete_piece(t_piece *piece)
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
	ft_putstr_fd("Nombre d'* : ", 2);
	ft_putnbr_fd(piece->wldc_tot, 2);
	ft_putendl_fd("", 2);
}

void	find_wldc(t_piece *piece, int nb)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (piece->piece[i])
	{
		j = 0;
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
			{
				count++;
				if (nb == count)
				{	
					piece->wldc_y = j;
					ft_putstr_fd("wldc j = :", 2);
					ft_putnbr_fd(j, 2);
					ft_putendl_fd("", 2);
					ft_putstr_fd("wldc i = :", 2);
					ft_putnbr_fd(i, 2);
					ft_putendl_fd("", 2);
					piece->wldc_x = i;
					return ;
				}
			}
			j++;
		}
		i++;
	}
}

void	get_player_pos(t_grid *grid)
{
	int	i;
	int	j;
	int	pos;

	grid->player_tot = 0;
	i = 0;
	pos = 0;
	ft_putendl_fd("", 2);
	ft_putendl_fd("get_player_pos", 2);
	ft_putendl_fd("", 2);
	while (i < grid->line && grid->table[i])
	{
		j = 0;
		ft_putstr_fd("i = :", 2);
		ft_putnbr_fd(i, 2);
		ft_putendl_fd("", 2);
		while (j < grid->col && grid->table[i][j])
		{
			ft_putstr_fd("j = :", 2);
			ft_putnbr_fd(j, 2);
			ft_putendl_fd("", 2);
			if (grid->table[i][j] == grid->player)
			{
				grid->player_pos[grid->player_tot] = (i) * grid->col + j;
				grid->player_tot++;
			}
			//pos++;
			j++;
		}
		i++;
	}
	ft_putendl_fd("sortie get_player_pos", 2);
}

int		check_if_outside_map(t_grid *grid, t_piece *piece, int i, int j)
{
	ft_putstr_fd("check entree", 2);
	if (grid->player_pos[piece->pos_nb] / (grid->col) - piece->wldc_x + i > grid->line - 1)
		return (0);
	else if (grid->player_pos[piece->pos_nb] / (grid->col) - piece->wldc_x + i < 0)
		return (0);
	else if (grid->player_pos[piece->pos_nb] % (grid->col) - piece->wldc_y + j > grid->col - 1)
		return (0);
	else if (grid->player_pos[piece->pos_nb] % (grid->col) - piece->wldc_y + j < 0)
		return (0);
	//est ce quon verifie vraiment les autres wldc ????
	ft_putstr_fd("check sortie", 2);
	return (1);
}

int		put_piece(t_grid *grid, t_piece *piece, int wldc_nb)
{
	int count;
	int i;
	int j;
	int savex;
	int savey;
	int	link;

	link = 0;
	ft_putendl_fd("", 2);
	ft_putendl_fd("putpiece", 2);
	ft_putendl_fd("", 2);
	count = 0;
	ft_putstr_fd("wldc_nb = :", 2);
	ft_putnbr_fd(wldc_nb, 2);
	ft_putendl_fd("", 2);
	find_wldc(piece, wldc_nb);
	ft_putstr_fd("wldc_x = :", 2);
	ft_putnbr_fd(piece->wldc_x, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("wldc_y = :", 2);
	ft_putnbr_fd(piece->wldc_y, 2);
	ft_putendl_fd("", 2);
	i = 0;
	ft_putendl_fd("", 2);
	ft_putstr_fd("pos = :", 2);
	ft_putnbr_fd(grid->player_pos[piece->pos_nb], 2);
	ft_putnbr_fd(grid->line, 2);
	ft_putstr_fd("\nx = ", 2);
	ft_putnbr_fd(grid->player_pos[piece->pos_nb] / (grid->col), 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("y = ", 2);
	ft_putnbr_fd(grid->player_pos[piece->pos_nb] % (grid->col), 2);
	ft_putstr_fd("\ncase = '", 2);
	ft_putendl_fd("'", 2);

	while (piece->piece[i])
	{
		j = 0;
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
			{
				ft_putstr_fd("j = :", 2);
				ft_putnbr_fd(j, 2);
				ft_putendl_fd("", 2);
				ft_putstr_fd("i = :", 2);
				ft_putnbr_fd(i, 2);
				ft_putendl_fd("", 2);
				if (!check_if_outside_map(grid, piece, i, j))
					return (0);
				ft_putstr_fd("\nx = ", 2);
				ft_putnbr_fd(grid->player_pos[piece->pos_nb] / (grid->col) - piece->wldc_x + i, 2);
				ft_putendl_fd("", 2);
				ft_putstr_fd("y = ", 2);
				ft_putnbr_fd(grid->player_pos[piece->pos_nb] % (grid->col) - piece->wldc_y + j, 2);
				ft_putstr_fd("\ncase = '", 2);
				ft_putchar_fd(grid->table[grid->player_pos[piece->pos_nb] / (grid->col) - piece->wldc_x + i][grid->player_pos[piece->pos_nb] % (grid->col)- piece->wldc_y + j], 2);
				ft_putendl_fd("'", 2);
				if (!link && grid->table[grid->player_pos[piece->pos_nb] / \
						(grid->col) -  piece->wldc_x + i][grid->player_pos[piece->pos_nb] \
						% (grid->col) - piece->wldc_y + j] == grid->player)
				{
					ft_putendl_fd("link", 2);
					savex = i;
					savey= j;
					link = 1;
				}
				else if  (grid->table[grid->player_pos[piece->pos_nb] / \
						(grid->col) - piece->wldc_x + i][grid->player_pos[piece->pos_nb] \
						% (grid->col)- piece->wldc_y + j] != '.')
				{
					ft_putendl_fd("pas possible a ces coord", 2);
					ft_putendl_fd("retour main", 2);
					return (0);
				}
				count++;
				ft_putstr_fd("count = :", 2);
				ft_putnbr_fd(count, 2);
				ft_putendl_fd("", 2);
			}
			if (count == piece->wldc_tot && link)
			{
				piece->pos[0] = grid->player_pos[piece->pos_nb] / (grid->col) - savex;
				piece->pos[1] = grid->player_pos[piece->pos_nb] % (grid->col) - savey;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	get_pos_score(t_pos *pos, t_grid *grid)
{
	if (grid->player == 'O')
	{
		if (pos->pos >= grid->enemy_start_pos)
			pos->score = pos->pos - grid->enemy_start_pos;
		else if (pos->pos < grid->enemy_start_pos)
			pos->score = grid->enemy_start_pos - pos->pos;
	}
}

void	add_psbl_pos(t_list **all_pos, t_piece *piece, t_grid *grid)
{
	t_pos *pos;

	pos = malloc(sizeof(t_pos));
	pos->x = piece->pos[0];
	pos->y = piece->pos[1];
	ft_putstr_fd("x = ", 2);
	ft_putnbr_fd(pos->x, 2);
	ft_putstr_fd("y = ",2);
	ft_putnbr_fd(pos->y, 2);
	ft_putstr_fd("\n",2);
	pos->pos = pos->x * grid->col + pos->y;
	get_pos_score(pos, grid);
	ft_putstr_fd("score = ",2);
	ft_putnbr_fd(pos->score, 2);
	ft_putstr_fd("\n",2);
	ft_lstpush(all_pos, pos, sizeof(t_pos));
}

void	find_all_possible_pos(t_grid *grid, t_piece *piece, t_list **all_pos)
{
	int		j;

	piece->pos_nb = 0;
	get_player_pos(grid);
	piece->pos = (int*)malloc(sizeof(int) * 2);
	ft_putstr_fd("oyoy",2);
	while (piece->pos_nb < grid->player_tot)
	{
		j = 1;
		while (j <= piece->wldc_tot)
		{
			if (put_piece(grid, piece, j))
			{
				ft_putendl_fd("ici", 2);
				add_psbl_pos(all_pos, piece, grid);
			}
			j++;
		}
		piece->pos_nb++;
	}
}

void	find_best_pos(t_list *all_pos, int *pos)
{
	int score;

	ft_putstr_fd("\n find_best_pos ", 2);
	score = 1000000000;
	while (all_pos)
	{
		ft_putstr_fd("\n score =  ", 2);
		ft_putnbr_fd(((t_pos*)all_pos->content)->score, 2);
		if (((t_pos*)all_pos->content)->score < score)
		{
			pos[0] = ((t_pos*)all_pos->content)->x;
			ft_putstr_fd("\n x = ", 2);
			ft_putnbr_fd(pos[0], 2);
			pos[1] = ((t_pos*)all_pos->content)->y;
			ft_putstr_fd("\n x = ", 2);
			ft_putnbr_fd(pos[1], 2);
		}
		all_pos = all_pos->next;
	}
}

int		*find_pos(t_grid *grid, t_piece *piece)
{
	t_list	*all_pos;
	int		*pos;

	ft_putendl_fd("find_pos", 2);
	pos = malloc(sizeof(int) * 2);
	all_pos = NULL;
	find_all_possible_pos(grid, piece, &all_pos);
	if (all_pos)
	{
		find_best_pos(all_pos, pos);
		ft_putstr_fd("LOLOLOL", 2);
		//	pos[0] = ((t_pos*)all_pos->content)->x;
		//	pos[1] = ((t_pos*)all_pos->content)->y;
		return (pos);
	}
	else
		return (NULL);
}
