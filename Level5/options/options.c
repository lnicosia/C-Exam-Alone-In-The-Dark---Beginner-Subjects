/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:51:54 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 17:17:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int		main(int ac, char **av)
{
	int		i;
	int		j;
	char	tab[32];

	i = 0;
	while (i < 32)
	{
		tab[i] = '0';
		i++;
	}
	if (ac == 1)
	{
		ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
		return (0);
	}
	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-' || (av[i][0] == '-' && av[i][1] == 'h'))
		{
			ft_putstr("options: abcdefghijklmnopqrstuvwxyz\n");
			return (0);
		}
		j = 1;
		while (av[i][j])
		{
			if (av[i][j] >= 'a' && av[i][j] <= 'z')
			{
				tab[31 - av[i][j] + 97] = '1';
			}
			else
			{
				ft_putstr("Invalid Option\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 32)
	{
		if (i > 0 && i % 8 == 0)
			ft_putchar(' ');
		ft_putchar(tab[i]);
		i++;
	}
	ft_putchar('\n');
	return (0);
}
