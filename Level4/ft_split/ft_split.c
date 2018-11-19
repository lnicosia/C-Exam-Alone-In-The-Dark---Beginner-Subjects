/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:11:34 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 15:07:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_nbr_of_words(char *str)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else if (str[i] < ' ' || str[i] > '~')
			return (0);
		else
		{
			nbr++;
			while (str[i] >= '!' && str[i] <= '~' && str[i])
			{
				i++;
			}
		}
	}
	return (nbr);
}

int		ft_allocate_words(char *str, char **res)
{
	int		nbr;
	int		i;
	int		size;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else
		{
			size = 0;
			while (str[i] >= '!' && str[i] <= '~' && str[i])
			{
				size++;
				i++;
			}
			if (!(res[nbr] = (char*)malloc(sizeof(*str) * (size + 1))))
				return (0);
			nbr++;
		}
	}
	return (1);
}

void	ft_fill_res(char *str, char **res)
{
	int		nbr;
	int		i;
	int		j;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		else
		{
			j = 0;
			while (str[i] >= '!' && str[i] <= '~' && str[i])
			{
				res[nbr][j] = str[i];
				j++;
				i++;
			}
			res[nbr][j] = '\0';
			nbr++;
		}
	}
}

char	**ft_split(char *str)
{
	int		words;
	char	**res;
	char	last_str;

	last_str = 0;
	if (str == NULL)
	{
		if (!(res = (char**)malloc(sizeof(char*))))
			return (0);
		res[0] = 0;
		return (res);
	}
	words = ft_nbr_of_words(str);
	if (!(res = (char**)malloc(sizeof(char*) * (words + 1))))
		return (0);
	if (!(ft_allocate_words(str, res)))
		return (0);
	ft_fill_res(str, res);
	res[words] = 0;
	return (res);
}
