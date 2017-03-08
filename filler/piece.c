/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:01:13 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/08 17:33:15 by agiulian         ###   ########.fr       */
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
	piece->wldc = 0;
	while (i < piece->line)
	{
		j = 0;
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
				piece->wldc++;
			j++;
		}
		i++;
	}
	ft_putstr_fd("Nombre d'* : ", 2);
	ft_putnbr_fd(piece->wldc, 2);
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
					piece->posy = j;
					ft_putstr_fd("wldc j = :", 2);
					ft_putnbr_fd(j, 2);
					ft_putendl_fd("", 2);
					ft_putstr_fd("wldc i = :", 2);
					ft_putnbr_fd(i, 2);
					ft_putendl_fd("", 2);
					piece->posx = i;
					return ;
				}
			}
			j++;
		}
		i++;
	}
}

int		*find_o_x(t_grid *grid, int nb, int *pos)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	ft_putendl_fd("", 2);
	ft_putendl_fd("find_Ox", 2);
	ft_putstr_fd("nb = ", 2);
	ft_putnbr_fd(nb, 2);
	ft_putendl_fd("", 2);
	while (grid->table[i])
	{
		j = 0;
		while (grid->table[i][j])
		{
			if (grid->table[i][j] == grid->player)
			{
				count++;
				if (count == nb)
				{
					pos[0] = i;
					pos[1] = j;
					ft_putnbr_fd(i, 2);
					ft_putendl_fd("", 2);
					ft_putnbr_fd(j, 2);
					ft_putendl_fd("", 2);
					return (pos);
				}
			}
			j++;
		}
		i++;
	}
	exit (0); // anti segfault
}

int		put_piece(t_piece *piece, t_grid *grid, int *pos, int nb)
{
	int count;
	int i;
	int j;

	ft_putendl_fd("", 2);
	ft_putendl_fd("putpiece", 2);
	count = 1;
	if (nb == piece->wldc)
		return (0);
	find_wldc(piece, nb);
	i = piece->posx;
	j = piece->posy + 1;
	ft_putstr_fd("entry j = :", 2);
	ft_putnbr_fd(j, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("entry i = :", 2);
	ft_putnbr_fd(i, 2);
	ft_putendl_fd("", 2);

	while (piece->piece[i])
	{
		while (piece->piece[i][j])
		{
			if (piece->piece[i][j] == '*')
			{
				ft_putstr_fd("put j = :", 2);
				ft_putnbr_fd(j, 2);
				ft_putendl_fd("", 2);
				ft_putstr_fd("put i = :", 2);
				ft_putnbr_fd(i, 2);
				ft_putendl_fd("", 2);
			//	if (pos[0] + i - piece->posx > grid->line || pos[1] + j - piece->posy > grid->col)
			//	{
			//		ft_putendl_fd("LOLOLOLOLOL", 2);
			//		grid->change = 1;
			//		return (0);
			//	}
				if (grid->table[pos[0] + i - piece->posx][pos[1] + j - piece->posy] != '.')
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
			if (count == piece->wldc)
			{
				pos[0] -= piece->posx;
				pos[1] -= piece->posy;
				ft_putstr_fd("pos[0] = :", 2);
				ft_putnbr_fd(pos[0], 2);
				ft_putendl_fd("", 2);
				ft_putstr_fd("pos[1] = :", 2);
				ft_putnbr_fd(pos[1], 2);
				ft_putendl_fd("", 2);
				ft_putendl_fd("pose piece", 2);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (put_piece(piece, grid, pos, nb + 1));
}
