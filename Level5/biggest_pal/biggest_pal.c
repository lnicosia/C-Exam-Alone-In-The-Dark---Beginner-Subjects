/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_pal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:55:35 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 15:22:48 by lnicosia         ###   ########.fr       */
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

int		check_pal(int start, int end, char *str)
{
	int	i;
	int	j;

	i = start;
	j = end;
	while (str[i] == str[j])
	{
		i++;
		j--;
	}
	if (i >= j)
	{
		write(1, str + start, end - start + 1);
		write(1, "\n", 1);
		return (end - start + 1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	i;
	int	j;
	int	len;
	int	size;
	int	size2;
	int	start;
	int	end;

	i = 0;
	j = 0;
	len = 0;
	size = 0;
	size2 = 0;
	start = 0;
	end = 0;
	if (ac == 2)
	{
		while (av[1][len])
			len++;
		size = len;
		while (size >= 0)
		{
			i = 0;
			while (size + i < len)
			{
				if (check_pal(i, size + i, av[1]) > 1)
					return (0);
				i++;
			}
			size--;
		}
	}
	ft_putchar('\n');
	return (0);
}
