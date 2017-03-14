/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:53:55 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/14 19:22:07 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_pos_score(t_pos *pos, t_grid *grid)
{	
	if (grid->player == 'O')
	{
		if (pos->pos >= grid->direction_1)
			pos->score = pos->pos - grid->direction_1;
		else if (pos->pos < grid->direction_1)
			pos->score = grid->direction_1 - pos->pos;
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
	if (!(grid->player_pos = (int*)malloc(sizeof(int) * grid->line * grid->col)))
		exit(-1);
	while (i < grid->line && grid->table[i])
	{
		j = 0;
		while (j < grid->col && grid->table[i][j])
		{
			if (grid->table[i][j] == grid->player)
			{
				grid->player_pos[grid->player_tot] = (i) * grid->col + j;
				grid->player_tot++;
			}
			j++;
		}
		i++;
	}
	ft_putendl_fd("sortie get_player_pos", 2);
}

int		get_player_pos_next(t_grid *grid, int pos)
{
	int	i;
	int	j;

	i = pos / grid->col;
	j = pos % grid->col;
	ft_putendl_fd("", 2);
	ft_putendl_fd("get_player_pos_next", 2);
	ft_putendl_fd("", 2);
	while (grid->table[i])
	{
		while (grid->table[i][j])
		{
			if (grid->table[i][j] == grid->player)
			{
				grid->pos1 = i * grid->col + j;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	ft_putendl_fd("sortie get_player_pos_next", 2);
	return (0);
}

int		get_player_pos_prev(t_grid *grid, int pos)
{
	int	i;
	int	j;

	i = pos / grid->col;
	j = pos % grid->col;
	ft_putendl_fd("", 2);
	ft_putendl_fd("get_player_pos_prev", 2);
	ft_putendl_fd("", 2);
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (grid->table[i][j] == grid->player)
			{
				grid->pos2 = i * grid->col + j;
				return (1);
			}
			j--;
		}
		j = grid->col - 1;
		i--;
	}
	ft_putendl_fd("sortie get_player_pos_rev", 2);
	return (0);
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
	if (grid->dir == 1)
		grid->pos1 = (pos->x + piece->wldc_x) * grid->col + (pos->y + piece->wldc_y);
	else
		grid->pos2 = (pos->x + piece->wldc_x) * grid->col + (pos->y + piece->wldc_y);
	pos->pos = pos->x * grid->col + pos->y;
//	get_pos_score(pos, grid);
	ft_putstr_fd("score = ",2);
	ft_putnbr_fd(pos->score, 2);
	ft_putstr_fd("\n",2);
	ft_lstpush(all_pos, pos, sizeof(t_pos));
}

void	find_pos_dir_one(t_grid *grid, t_piece *piece, t_list **all_pos)
{
	int		j;
	int		pos;

	grid->dir = 2;
	piece->pos_nb = 0;
	piece->pos = (int*)malloc(sizeof(int) * 2);
	ft_putstr_fd("dir one",2);
	piece->pos_nb = 0;
	if (!(grid->player_pos = (int*)malloc(sizeof(int) * 1)))
		exit(-1);
	while ((grid->pos1 < grid->line * grid->col - 1) && get_player_pos_next(grid, grid->pos1))
	{
		j = 1;
		grid->player_pos[0] = grid->pos1;
		while (j <= piece->wldc_tot)
		{
			if (put_piece(grid, piece, j))
			{
				ft_putendl_fd("ici", 2);
				add_psbl_pos(all_pos, piece, grid);
				return ;
			}
			j++;
		}
		grid->pos1++;
	}
}

void	find_pos_dir_two(t_grid *grid, t_piece *piece, t_list **all_pos)
{
	int		j;
	int		i;

	grid->dir = 1;
	piece->pos_nb = 0;
	piece->pos = (int*)malloc(sizeof(int) * 2);
	ft_putstr_fd("dir 2",2);
	piece->pos_nb = 0;
	if (!(grid->player_pos = (int*)malloc(sizeof(int) * 1)))
		exit(-1);
	while (grid->pos2 >= 0 && get_player_pos_prev(grid, grid->pos2))
	{
		grid->player_pos[0] = grid->pos2;
		j = 1;
		while (j <= piece->wldc_tot)
		{
			if (put_piece(grid, piece, j))
			{
				ft_putendl_fd("ici", 2);
				add_psbl_pos(all_pos, piece, grid);
				return ;
			}
			j++;
		}
		grid->pos2--;
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
	if (grid->dir == 1)
		find_pos_dir_one(grid, piece, &all_pos);
	else
		find_pos_dir_two(grid, piece, &all_pos);
	if (all_pos)
	{
	//	pos[0] = ((t_pos*)all_pos->content)->x;
	//	pos[1] = ((t_pos*)all_pos->content)->y;
		pos[0] = piece->pos[0];
		pos[1] = piece->pos[1];
		//find_best_pos(all_pos, pos);
		ft_putstr_fd("LOLOLOL", 2);
		return (pos);
	}
	else
		return (NULL);
}

