/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:14:38 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 18:21:31 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int ac, char **av)
{
	int	i;
	int	start;
	int	len;

	i = 0;
	len = 0;
	start = 0;
	if (ac >= 2)
	{
		while (av[1][i] == ' ' || av[1][i] == '\t')
		{
			i++;
			start++;
		}
		len = start;
		while (av[1][i] && av[1][i] != ' ' && av[1][i] != '\t')
		{
			i++;
			len++;
		}
		while (av[1][i] == ' ' || av[1][i] == '\t')
			i++;
		while (av[1][i])
		{
			while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
			{
				write(1, &av[1][i], 1);
				i++;
			}
			write (1, " ", 1);
			while (av[1][i] == ' ' || av[1][i] == '\t')
				i++;
		}
		while (start < len)
		{
			write(1, &av[1][start], 1);
			start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
