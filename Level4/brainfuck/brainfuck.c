/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:11:28 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 20:14:55 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		main(int ac, char **av)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (ac == 2)
	{
		if (!(str = (char*)malloc(sizeof(*str) * 2048)))
			return (-1);
		while (j < 2048)
		{
			str[j] = 0;
			j++;
		}
		j = 0;
		while (av[1][j])
		{
			//write(1, &av[1][j], 1);
			if (av[1][j] == '>')
				str++;
			else if (av[1][j] == '<')
				str--;
			else if (av[1][j] == '+')
				(*str)++;
			else if (av[1][j] == '-')
				(*str)--;
			else if (av[1][j] == '.')
			write(1, str, 1);
			else if (av[1][j] == '[' && !*str)
			{
				i++;
				while (i != 0)
				{
					j++;
					if (av[1][j] == '[')
						i++;
					else if (av[1][j] == ']')
						i--;
				}
			}
			else if (av[1][j] == ']' && *str)
			{
				i++;
				while (i != 0)
				{
					j--;
					if (av[1][j] == ']')
						i++;
					else if (av[1][j] == '[')
						i--;
				}
			}
			j++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
