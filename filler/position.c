/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:53:55 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/15 21:35:49 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*void	get_pos_score(t_pos *pos, t_grid *grid)
  {	
  if (grid->player == 'O')
  {
  if (pos->pos >= grid->direction_1)
  pos->score = pos->pos - grid->direction_1;
  else if (pos->pos < grid->direction_1)
  pos->score = grid->direction_1 - pos->pos;
  }
  }*/

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

/*void	get_player_pos(t_grid *grid)
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
  }*/

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
			if (grid->table[i][j] == '.')
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
			if (grid->table[i][j] == '.')
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

int 	get_pos_from_start(t_grid *grid, t_piece *piece, int pos)
{
	int	i;
	int	j;

		ft_putstr_fd("\npos1 start=", 2);
		ft_putnbr_fd(grid->pos1, 2);
		ft_putendl_fd("", 2);
	i = pos / grid->col;
	j = pos % grid->col;
	while (i <= grid->line)
	{
		while (j <= grid->col)
		{
			if (i + piece->height <= grid->line && j + piece->width <= grid->col)
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

int 	get_pos_from_end(t_grid *grid, t_piece *piece, int pos)
{
	int	i;
	int	j;

	i = pos / grid->col;
	j = pos % grid->col;
	while (i >= 0)
	{
		while (j >= 0)
		{
			if (i - piece->height >= 0 && j - piece->width  >= 0)
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

/*void	add_psbl_pos(t_list **all_pos, t_piece *piece, t_grid *grid)
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
}*/

int		find_pos_dir_one(t_grid *grid, t_piece *piece, t_list **all_pos)
{
	int		j;
	int		pos;

	grid->dir = 2;
	grid->pos1 = 0;
	piece->pos_nb = 0;
	piece->pos = (int*)malloc(sizeof(int) * 2);
	ft_putstr_fd("dir one",2);
	piece->pos_nb = 0;
	if (!(grid->player_pos = (int*)malloc(sizeof(int) * 1)))
		exit(-1);
	while ((grid->pos1 < grid->line * grid->col - 1) && get_pos_from_start(grid, piece, grid->pos1))
	{
		grid->player_pos[0] = grid->pos1;
			if (put_piece(grid, piece))
			{
				ft_putendl_fd("ici", 2);
				//add_psbl_pos(all_pos, piece, grid);
				return (1);
			}
			j--;
		ft_putstr_fd("\npos1 =", 2);
		ft_putnbr_fd(grid->pos1, 2);
		ft_putendl_fd("", 2);
		grid->pos1++;
	}
	return (0);
}

int		find_pos_dir_two(t_grid *grid, t_piece *piece, t_list **all_pos)
{
	int		j;
	int		i;

	grid->dir = 1;
	piece->pos_nb = 0;
	grid->pos2 = grid->col * grid->line - 1;
	piece->pos = (int*)malloc(sizeof(int) * 2);
	ft_putstr_fd("dir 2",2);
	piece->pos_nb = 0;
	if (!(grid->player_pos = (int*)malloc(sizeof(int) * 1)))
		exit(-1);
	while (grid->pos2 >= 0 && get_pos_from_end(grid, piece, grid->pos2))
	{
		grid->player_pos[0] = grid->pos2;
			if (put_piece_reverse(grid, piece))
			{
				ft_putendl_fd("ici", 2);
				//		add_psbl_pos(all_pos, piece, grid);
				return (1);
			}
			j++;
		grid->pos2--;
	}
	return (0);
}

/*void	find_best_pos(t_list *all_pos, int *pos)
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
  }*/

int		*find_pos(t_grid *grid, t_piece *piece)
{
	t_list	*all_pos;
	int		*pos;
	int		ret;

	ft_putendl_fd("find_pos", 2);
	pos = malloc(sizeof(int) * 2);
	all_pos = NULL;
	if (grid->dir == 1)
		ret = find_pos_dir_one(grid, piece, &all_pos);
	else if (grid->dir == 2)
		ret = find_pos_dir_two(grid, piece, &all_pos);
	if (ret)
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

