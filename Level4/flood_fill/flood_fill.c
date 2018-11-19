/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:06:06 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 14:15:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void	fill(char **tab, int i, int j, char c, int xmax, int ymax)
{
	tab[i][j] = 'F';
	if (i + 1 <= ymax && tab[i + 1][j] == c)
		fill(tab, i + 1, j, c, xmax, ymax);
	if (i - 1 >= 0 && tab[i - 1][j] == c)
		fill(tab, i - 1, j, c, xmax, ymax);
	if (j + 1 < xmax && tab[i][j + 1] == c)
		fill(tab, i, j + 1, c, xmax, ymax);
	if (j - 1 >= 0 && tab[i][j - 1] == c)
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
