/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:20:00 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 18:45:14 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"
#include <unistd.h>
#include <stdlib.h>

void	flood_fill(char **tab, t_point size, t_point begin);

void	putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	print_tab(char **tab)
{
	while (*tab)
	{
		putstr(*tab);
		write(1, "\n", 1);
		tab++;
	}
}

int main(void)
{
	int	i = 0;
	int	j;
	t_point size = { 8, 5 };
	t_point begin = { 2, 2 };
	char **area;
	char *zone[] = {
		"00000000",
		"00000000",
		"11001001",
		"11100001",
		"11101001"
	};
	area = (char**)malloc(sizeof(*area) * 6);
	area[5] = 0;
	while (i < 5)
	{
		area[i] = (char*)malloc(sizeof(**area) * 9);
		area[i][8] = 0;
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 8)
		{
			area[i][j] = zone[i][j];
			j++;
		}
		i++;
	}
	//area = make_area(zone);
	print_tab(area);
	flood_fill(area, size, begin);
	write(1, "\n", 1);
	print_tab(area);
	return (0);
}
