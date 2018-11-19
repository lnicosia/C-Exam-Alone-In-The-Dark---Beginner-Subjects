/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moment.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:11:21 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/19 16:16:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		nblen(unsigned int nbr)
{
	unsigned int	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void	fill_str(char *str, int len, unsigned int duration, int s)
{
	str[len] = '\0';
	str[len - 1] = '.';
	str[len - 2] = 'o';
	str[len - 3] = 'g';
	str[len - 4] = 'a';
	str[len - 5] = ' ';
	if (s == 1)
		str[len - 6] = 's';
	if (duration >= 60 && duration < 3600)
	{
		str[len - 6 - s] = 'e';
		str[len - 7 - s] = 't';
		str[len - 8 - s] = 'u';
		str[len - 9 - s] = 'n';
		str[len - 10 - s] = 'i';
		str[len - 11 - s] = 'm';
		str[len - 12 - s] = ' ';
	}
	else if (duration >= 3600 && duration < 86400)
	{
		str[len - 6 - s] = 'r';
		str[len - 7 - s] = 'u';
		str[len - 8 - s] = 'o';
		str[len - 9 - s] = 'h';
		str[len - 10 - s] = ' ';
	}
	else if (duration >= 86400 && duration < 2592000) 
	{
		str[len - 6 - s] = 'y';
		str[len - 7 - s] = 'a';
		str[len - 8 - s] = 'd';
		str[len - 9 - s] = ' ';
	}
	else if (duration >= 2592000)
	{
		str[len - 6 - s] = 'h';
		str[len - 7 - s] = 't';
		str[len - 8 - s] = 'n';
		str[len - 9 - s] = 'o';
		str[len - 10 - s] = 'm';
		str[len - 11 - s] = ' ';
	}
	else
	{
		str[len - 6 - s] = 'd';
		str[len - 7 - s] = 'n';
		str[len - 8 - s] = 'o';
		str[len - 9 - s] = 'c';
		str[len - 10 - s] = 'e';
		str[len - 11 - s] = 's';
		str[len - 12 - s] = ' ';
	}

}

void	fill_duration(char *str, int len, int div)
{
	int i;

	i = 0;
	while (len >= 0)
	{
		str[len - 1] = div % 10 + '0';
		div = div / 10;
		len--;
	}
}

char	*moment(unsigned int duration)
{
	char	*str;
	int		div;
	int		len;
	int		s;
	int		charlen;

	s = 0;
	if (duration >= 60 && duration < 3600)
	{
		div = duration / 60;
		charlen = 6;
	}
	else if (duration >= 3600 && duration < 86400)
	{
		div = duration / 3600;
		charlen = 4;
	}
	else if (duration >= 86400 && duration < 2592000)
	{
		div = duration / 86400;
		charlen = 3;
	}
	else if (duration >= 2592000)
	{
		div = duration / 2592000;
		charlen = 5;
	}
	else
	{
		div = duration;
		charlen = 6;
	}
	if (div != 1)
		s++;
	len = nblen(div) + charlen + 6 + s;
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (0);
	fill_str(str, len, duration, s);
	fill_duration(str, nblen(div), div);
	return (str);
}
