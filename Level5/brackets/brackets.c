/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:18:48 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/04 19:36:52 by lnicosia         ###   ########.fr       */
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

int		check_bracket(char *str, char c)
{
	int		i;
	char	s;

	i = 0;
	if (c == '(')
		s = ')';
	else if (c == '[')
		s = ']';
	else if (c == '{')
		s = '}';
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			return (check_bracket(str + i + 1, str[i]));
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (str[i] == s)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}

int		check_nb(char *str)
{
	int	i;
	int	c1;
	int	c2;

	i = 0;
	c1 = 0;
	c2 = 0;
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			c1++;
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			c2++;
		i++;
	}
	if (c1 != c2)
		return (0);
	return (1);
}

int		brackets(char *str)
{
	int	i;

	i = 0;
	if (check_nb(str) == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			if (check_bracket(str + i + 1, str[i]) == 0)
				return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac > 1)
	{
		while (av[++i])
			if (brackets(av[i]))
				ft_putstr("OK\n");
			else
				ft_putstr("Error\n");
	}
	else
		ft_putchar('\n');
	return (0);
}
