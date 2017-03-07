/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:23:24 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/08 00:15:01 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/printf/ft_printf.h"
# include "libft/libft/includes/get_next_line.h"

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
	char		*raw;
	char		*edited;
}				t_piece;

#endif
