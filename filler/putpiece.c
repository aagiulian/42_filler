/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:01:13 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/14 15:03:47 by agiulian         ###   ########.fr       */
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
						(grid->col) - piece->wldc_x + i][grid->player_pos[piece->pos_nb] \
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
