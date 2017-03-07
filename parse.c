/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:20:48 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/07 19:31:24 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_grid *grid, char **line)
{
	get_next_line(0, line);
	if ((*line)[10] == '1')
		grid->player = 'O';
	else
		grid->player = 'X';
	//ft_strdel(line);
	free(*line);
}

void	get_grid_size(t_grid *grid, char **line)
{
	char *str;

	if (grid->player == 'O')
	{
		get_next_line(0, line);
		free(*line);
		get_next_line(0, line);
		free(*line);
	}
	get_next_line(0, line);
	str = *line + 8;
	grid->line = ft_atoi(*line + 8);
	while (*str != ' ')
		str++;
	grid->col = ft_atoi(str + 1);
}

/*void	init_t_grid(t_grid grid)
{
	grid = malloc(sizeof(t_grid));
}
*/
int		main(void)
{
	t_grid	*grid;
	char	*line;
	int		fd;

	fd = open("test", O_RDWR); // DEBUG
	dup2(fd, 2);	// DEBUG

	grid = malloc(sizeof(t_grid));
	get_player(grid, &line);
	get_grid_size(grid, &line);

	ft_putendl_fd(line, fd);
	ft_putnbr_fd(grid->line, fd);
	ft_putnbr_fd(grid->col, fd);

	return (0);
}
