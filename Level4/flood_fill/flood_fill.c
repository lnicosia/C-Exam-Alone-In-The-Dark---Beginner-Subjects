/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:06:06 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 13:09:19 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void	fill(char **tab, int i, int j, char c, int xmax, int ymax)
{
	if (tab[i][j] == c)
		tab[i][j] = 'F';
	if (tab[i + 1][j] != 'F' && i + 1 < ymax)
		fill(tab, i + 1, j, c, xmax, ymax);
	if (tab[i - 1][j] != 'F' && i - 1 > 0)
		fill(tab, i - 1, j, c, xmax, ymax);
	if (tab[i][j + 1] != 'F' && j + 1 < xmax)
		fill(tab, i, j + 1, c, xmax, ymax);
	if (tab[i][j - 1] != 'F' && j - 1 > 0)
		fill(tab, i, j - 1, c, xmax, ymax);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	c;
	int		i;
	int		j;

	i = begin.y - 1;
	j = begin.x - 1;
	c = tab[i][j];
	fill(tab, i, j, c, size.x - 1, size.y - 1);
}
