/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_mate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 10:49:29 by exam              #+#    #+#             */
/*   Updated: 2019/03/19 12:08:52 by exam             ###   ########.fr       */
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

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_pion(char **av, int i, int j)
{
	if (av[i - 1][j - 1] == 'K' || av[i - 1][j + 1] == 'K')
		return (1);
	return (0);
}

int		check_fou(char **av, int y, int x)
{
	int	i;
	int	j;

	i = y + 1;
	j = 1;
	while (av[i])
	{
		if (av[i][x + j] == 'P'
		|| av[i][x + j] == 'B'
		|| av[i][x + j] == 'R'
		|| av[i][x + j] == 'Q')
			break;
		if (av[i][x + j] == 'K')
			return (1);
		i++;
		j++;
	}
	i = y + 1;
	j = 1;
	while (av[i])
	{
		if (av[i][x - j] == 'P'
		|| av[i][x - j] == 'B'
		|| av[i][x - j] == 'R'
		|| av[i][x - j] == 'Q')
			break;
		if (av[i][x - j] == 'K')
			return (1);
		i++;
		j++;
	}
	i = y - 1;
	j = 1;
	while (i > 0)
	{
		if (av[i][x + j] == 'P'
		|| av[i][x + j] == 'B'
		|| av[i][x + j] == 'R'
		|| av[i][x + j] == 'Q')
			break;
		if (av[i][x + j] == 'K')
			return (1);
		i--;
		j++;
	}
	i = y - 1;
	j = 1;
	while (i > 0)
	{
		if (av[i][x - j] == 'P'
		|| av[i][x - j] == 'B'
		|| av[i][x - j] == 'R'
		|| av[i][x - j] == 'Q')
			break;
		if (av[i][x - j] == 'K')
			return (1);
		i--;
		j++;
	}
	return (0);
}

int		check_tour(char **av, int y, int x)
{
	int	i;

	i = y + 1;
	while (av[i])
	{
		if (av[i][x] == 'P'
		|| av[i][x] == 'B'
		|| av[i][x] == 'R'
		|| av[i][x] == 'Q')
			break;
		if (av[i][x] == 'K')
			return (1);
		i++;
	}
	i = y - 1;
	while (i > 0)
	{
		if (av[i][x] == 'P'
		|| av[i][x] == 'B'
		|| av[i][x] == 'R'
		|| av[i][x] == 'Q')
			break;
		if (av[i][x] == 'K')
			return (1);
		i--;
	}
	i = x + 1;
	while (av[y][i])
	{
		if (av[y][i] == 'P'
		|| av[y][i] == 'B'
		|| av[y][i] == 'R'
		|| av[y][i] == 'Q')
			break;
		if (av[y][i] == 'K')
			return (1);
		i++;
	}
	i = x - 1;
	while (av[y][i])
	{
		if (av[y][i] == 'P'
		|| av[y][i] == 'B'
		|| av[y][i] == 'R'
		|| av[y][i] == 'Q')
			break;
		if (av[y][i] == 'K')
			return (1);
		i--;
	}
	return (0);
}

int		check_entry(int ac, char **av)
{
	int	i;
	int	j;
	int	size;
	int	king;

	size = 0;
	king = 0;
	if (ac > 1)
	{
		i = 1;
		size = ft_strlen(av[1]);
		if (size != (ac - 1))
		{
			ft_putchar('\n');
			return (0);
		}
		while (av[i])
		{
			if (ft_strlen(av[i]) != size)
			{
				ft_putchar('\n');
				return (0);
			}
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] == 'K')
					king++;
				j++;
			}
			i++;
		}
		if (king != 1)
		{
			ft_putchar('\n');
			return (0);
		}
	}
	else
		ft_putchar('\n');
	return (size);
}

int		check_plateau(char **av, int size)
{
	int	i;
	int	j;

	i = 1;
	(void)size;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == 'P')
				if (check_pion(av, i, j) == 1)
					return (1);
			if (av[i][j] == 'B')
				if (check_fou(av, i, j) == 1)
					return (1);
			if (av[i][j] == 'R')
				if (check_tour(av, i, j) == 1)
					return (1);
			if (av[i][j] == 'Q')
			{
				if (check_tour(av, i, j) == 1)
					return (1);
				if (check_fou(av, i, j) == 1)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	size;

	if ((size = check_entry(ac, av)) != 0)
	{
		if (check_plateau(av, size) == 1)
			ft_putstr("Success\n");
		else
			ft_putstr("Fail\n");
	}
	return (0);
}
