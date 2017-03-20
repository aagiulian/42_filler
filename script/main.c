/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:35:57 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/16 15:36:23 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *filler_path;
	char **maps;
	char **players;
	char *p1;
	char *p2;
	
	filler_path = "./filler_vm";
	p1 = "-p1";
	p2 = "-p2";
	maps = (char**)malloc(sizeof(char*) * 4);
	maps[0] = " -f maps/maps00";
	maps[1] = " -f maps/maps01";
	maps[2] = " -f maps/maps02";
	maps[3] = NULL;
	players = (char**)malloc(sizeof(char*) * 8);
	players[0] = " players/agiulian.filler";
	players[1] = " players/abanlin.filler";
	players[2] = " players/carli.filler";
	players[3] = " players/champely.filler";
	players[4] = " players/grati.filler";
	players[5] = " players/hcao.filler";
	players[6] = " players/superjeannot.filler";
	players[7] = NULL;
	execl(filler_path, maps[0], p1, players[1]);
	return (0);
}
