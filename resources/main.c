/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 14:35:57 by agiulian          #+#    #+#             */
/*   Updated: 2017/03/17 18:14:24 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

void	map00(void)
{
	int		fd;
	int		i;
	int 	score;
	char    buf[4097];

	i = 0;
	score = 0;
	printf("|--------------------------|\n");
	printf("|          MAP 00          |\n");
	printf("|--------------------------|\n");
	printf("%-12s VS    %-12s :", "agiulian", "abanlin");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 players/agiulian.filler -p2 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "carli");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 players/agiulian.filler -p2 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "champely");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 players/agiulian.filler -p2 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "grati");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 players/agiulian.filler -p2 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "hcao");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 players/agiulian.filler -p2 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "superjeannot");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p1 players/agiulian.filler -p2 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "abanlin", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 players/agiulian.filler -p1 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "carli", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 players/agiulian.filler -p1 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "champely", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 players/agiulian.filler -p1 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "grati", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 players/agiulian.filler -p1 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "hcao", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 players/agiulian.filler -p1 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "superjeannot", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map00 -p2 players/agiulian.filler -p1 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
}


void	map01(void)
{
	int		fd;
	int		i;
	int 	score;
	char    buf[4097];

	i = 0;
	score = 0;
	printf("|--------------------------|\n");
	printf("|          MAP 01          |\n");
	printf("|--------------------------|\n");
	printf("%-12s VS    %-12s :", "agiulian", "abanlin");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 players/agiulian.filler -p2 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "carli");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 players/agiulian.filler -p2 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "champely");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 players/agiulian.filler -p2 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "grati");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 players/agiulian.filler -p2 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "hcao");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 players/agiulian.filler -p2 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "superjeannot");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p1 players/agiulian.filler -p2 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "abanlin", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 players/agiulian.filler -p1 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "carli", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 players/agiulian.filler -p1 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "champely", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 players/agiulian.filler -p1 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "grati", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 players/agiulian.filler -p1 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "hcao", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 players/agiulian.filler -p1 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "superjeannot", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map01 -p2 players/agiulian.filler -p1 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
}

void	map02(void)
{
	int		fd;
	int		i;
	int 	score;
	char    buf[4097];

	i = 0;
	score = 0;
	printf("|--------------------------|\n");
	printf("|          MAP 02          |\n");
	printf("|--------------------------|\n");
	printf("%-12s VS    %-12s :", "agiulian", "abanlin");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 players/agiulian.filler -p2 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "carli");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 players/agiulian.filler -p2 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "champely");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 players/agiulian.filler -p2 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "grati");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 players/agiulian.filler -p2 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "hcao");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 players/agiulian.filler -p2 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "agiulian", "superjeannot");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p1 players/agiulian.filler -p2 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "abanlin", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 players/agiulian.filler -p1 players/abanlin.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "carli", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 players/agiulian.filler -p1 players/carli.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "champely", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 players/agiulian.filler -p1 players/champely.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "grati", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 players/agiulian.filler -p1 players/grati.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "hcao", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 players/agiulian.filler -p1 players/hcao.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
	i = 0;
	score = 0;
	printf("%-12s VS    %-12s :", "superjeannot", "agiulian");
	while (i < 5)
	{
		system("ruby filler_vm -q -f maps/map02 -p2 players/agiulian.filler -p1 players/superjeannot.filler > script_trace");
		fd = open("filler.trace", O_RDONLY);
		read(fd, buf, 4096);
		if (strstr(buf, "agiulian"))
				score++;
		i++;
	}
	printf("%i / %i ", score, i);
	if (score >= 3)
		printf("\x1B[32mWin\x1B[0m\n");
	else	
		printf("\x1B[31mLoose\x1B[0m\n");
}

int	main(void)
{
	printf("------------------------\n");
	printf("FILLER ANALYSIS SCRIPT :\n");
	printf("------------------------\n");
	printf("Each map will be played,\nPlayer will play in both position,\nIf more than 3/5 victories,\n WIN otherwise LOOSE\n   GOOD LUCK\n");
	map00();
	map01();
	//map02();
	return (0);
}
