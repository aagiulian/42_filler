/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putpiece.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 12:01:13 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/16 14:19:37 by agiulian         ###   ########.fr       */
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
	ft_putstr_fd("Height : ", 2);
	ft_putnbr_fd(piece->height, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("Width : ", 2);
	ft_putnbr_fd(piece->width, 2);
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
	ft_putendl_fd("EDITED :", 2);
	while (piece->edited[++i])
		ft_putendl_fd(piece->edited[i], 2);
}

int		put_piece(t_grid *grid, t_piece *piece)
{
	int i;
	int j;
	int count;
	int	link;

	ft_putendl_fd("\nputpiece NEW", 2);
	i = 0;
	count = 0;
	link = 0;
	ft_putstr_fd("pos = :", 2);
	ft_putnbr_fd(grid->player_pos[piece->pos_nb], 2);
	ft_putendl_fd("", 2);
	while (piece->edited[i])
	{
		j = 0;
		while (piece->edited[i][j])
		{
			if (piece->edited[i][j] == '*')
			{
				if (!link && grid->table[grid->player_pos[piece->pos_nb] / \
						(grid->col) + i][grid->player_pos[piece->pos_nb] \
						% (grid->col) + j] == grid->player)
				{
					ft_putendl_fd("link", 2);
					link = 1;
				}
				else if (grid->table[grid->player_pos[piece->pos_nb] / \
						(grid->col) + i][grid->player_pos[piece->pos_nb] \
						% (grid->col) + j] != '.')
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
				piece->pos[0] = grid->player_pos[piece->pos_nb] / (grid->col) - piece->xmin;
				piece->pos[1] = grid->player_pos[piece->pos_nb] % (grid->col) - piece->ymin;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		put_piece_reverse(t_grid *grid, t_piece *piece)
{
	int i;
	int j;
	int count;
	int	link;

	ft_putendl_fd("\nputpiece reverse", 2);
	i = piece->height - 1;
	count = 0;
	link = 0;
	ft_putstr_fd("pos = :", 2);
	ft_putnbr_fd(grid->player_pos[piece->pos_nb], 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("height = :", 2);
	ft_putnbr_fd(piece->height, 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("width = :", 2);
	ft_putnbr_fd(piece->width, 2);
	ft_putendl_fd("", 2);
	while (i >= 0)
	{
		j = piece->width - 1;
		while (j >= 0)
		{
			if (piece->edited[i][j] == '*')
			{
				if (!link && grid->table[grid->player_pos[piece->pos_nb] / \
						(grid->col) - piece->height + 1 + i][grid->player_pos[piece->pos_nb] \
						% (grid->col) - piece->width + 1 + j] == grid->player)
				{
					ft_putendl_fd("link", 2);
					link = 1;
				}
				else if (grid->table[grid->player_pos[piece->pos_nb] / \
						(grid->col) - piece->height + 1 + i][grid->player_pos[piece->pos_nb] \
						% (grid->col) - piece->width + 1 + j] != '.')
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
				piece->pos[0] = grid->player_pos[piece->pos_nb] / (grid->col) - piece->xmax;
				piece->pos[1] = grid->player_pos[piece->pos_nb] % (grid->col) - piece->ymax;
				return (1);
			}
			j--;
		}
		i--;
	}
	return (0);
}
